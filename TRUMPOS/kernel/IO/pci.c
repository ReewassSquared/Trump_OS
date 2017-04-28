#include <system.h>
#include <drivers/pci.h>

unsigned int read_pci(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset, const uint8_t length) //reads from pci
{
	unsigned int ret;
	const uint32_t value = 0x80000000 | (bus << 0x10) | (dev << 0xB) | (func << 0x8) | (port_offset & 0xFC /*1111 1100*/ );
	outportd(0x0CF8, value);
	ret = inportd(0x0CFC + (port_offset & 0x3 /*0000 0011*/ ));
	ret &= (0xFFFFFFFF >> ((4 - length) * 8));

	return ret;
}

void write_pci(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset, const uint8_t length, const uint32_t write) //writes to pci
{
	uint32_t value = 0x80000000 | (bus << 0x10) | (dev << 0xB) | (func << 0x8) | (port_offset & 0xFC);
	outportd(0x0CF8, value);
	value = inportd(0x0CFC + (port_offset & 0x03));
	if(length != 4)
	{
		value &= (0xFFFFFFFF << (length * 8));
	}
	else
	{
		value = 0;
	}
	value |= write;
	outportd(0x0CFC + (port_offset & 0x03), value);
}

unsigned int pci_memory_range(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset)
{
	uint32_t command_register = read_pci(bus, dev, func, 0x04, 2);
	write_pci(bus, dev, func, 0x04, 2, command_register & ~0x07);
	uint32_t origin0 = read_pci(bus, dev, func, port_offset, 4);
	uint32_t origin1;
	if((origin0 & 0x07) == 0x04)
	{
		origin1 = read_pci(bus, dev, func, port_offset + 4, 4);
	}
	write_pci(bus, dev, func, port_offset, 4, 0xFFFFFFFF);
	if((origin0 & 0x07) == 0x04)
	{
		write_pci(bus, dev, func, port_offset + 4, 4, 0xFFFFFFFF);
	}

	uint32_t range[2] = {0,0};
	range[0] = read_pci(bus, dev, func, port_offset, 4);
	if((origin0 & 0x07) == 0x04)
	{
		range[1] = read_pci(bus, dev, func, port_offset + 4, 4);
	}
	write_pci(bus, dev, func, port_offset, 4, origin0);
	if((origin0 & 0x07) == 0x04)
	{
		write_pci(bus, dev, func, port_offset + 4, 4, origin1);
	}

	write_pci(bus, dev, func, 0x04, 2, command_register);

	if(origin0 & 1)
	{
		origin0 = range[0];
		if((origin0 & 0xFFFF0000) == 0)
		{
			origin0 |= 0xFFFF0000;
		}
		return (~(origin0 & (uint32_t) ~0x1) + 1);
	}
	else
	{
		return (~(range[0] & (uint32_t) ~0xF) + 1);
	}
}

void uhci_pci_init(uint8_t bus, uint8_t dev, uint8_t func, uint32_t new_base, uint8_t new_irq) //special controller initializer for the UHCI
{
	write_pci(bus, dev, func, 0x20, 4, new_base);		//sets the new memory address to use for the BAR4.
	write_pci(bus, dev, func, 0x34, 4, 0x00000000);		//same thing as below... \|/
	write_pci(bus, dev, func, 0x38, 4, 0x00000000);		//clears the data stored in the reserved fields of the pci config space.
	write_pci(bus, dev, func, 0x3C, 1, (new_irq & 0x0F));	//sets the new IRQ. better hope it's not already mapped!
	write_pci(bus, dev, func, 0x04, 2, 0x0005);		//writes to command register; enables I/O access and bus mastering.
	write_pci(bus, dev, func, 0xC0, 2, 0xF800);		//set legacy support register to turn off all legacy support for keyboards and mice.
}

void search_for_usb_controllers()
{
	char  type[6][10] = { "          ", "  (UHCI)  ", "  (OHCI)  ", "  (EHCI)  ", "  (xHCI)  ", " (Unknown)" };
	uint32_t index;
	uint32_t base = 0;
	uint32_t size = 0;
	struct PCI_CONFIG data; //the pci config space for all the things.
	uint32_t *pci_data = (uint32_t *) &data; //casting to avoid warnings...
	for(int x = 0; x < 64; x++) //cycles through all the pci buses (we only need to worry about the first 64; chances are we won't encounter a computer with more than 64 of these.
	{
		for(int y = 0; y < 32; y++) //cycles through all the devices on this pci bus.
		{
			for(int z = 0; z < 8; z++) //cycles through all the functions on this pci bus device.
			{
				if(read_pci(x, y, z, 0x00, sizeof(uint16_t)) != 0xFFFF /*the code for a nonexistent pci thingy*/) //is this function defined?
				{
					for(int i = 0; i < 64; i++) //if so...
					{
						pci_data[i] = read_pci(x, y, z, (i << 2), sizeof(uint32_t)); //...set the PCI_CONFIG with all of the information!
					}

					if(data.CLASS_CODE == 0x0C && data.SUBCLASS_CODE == 0x03) //now we check if that function is a USB!
					{
						index = (data.PROGRAMMING_INTERFACE >> 4); //with this, we can use this 4-bit code to check which type of controller it is.
						if(index > 3) //since we don't have controllers over 3, and if we do, we return some unknown type
						{
							index = 4; //set to four.
						}
						if(data.PROGRAMMING_INTERFACE == 0x00) //check for UHCI, since UHCI is special and uses BAR4
						{
							base = data.BAR4;
							size = pci_memory_range(x, y, z, 0x20);
							uhci_pci_init(x, y, z, base, data.IRQ_LINE); //initializes the UHCI controller
						}
						else
						{
							base = data.BAR0;
							size = pci_memory_range(x, y, z, 0x10);
						}
						
						index++;

						putstr("\nUSB-COMPATABLE DEVICE ENTRY FOUND: ");
						for(int x = 0; x < 10; x++)
						{
							putchar(type[index][x]);
						}
						putstr("\nBUS = ");
						putstr(itoa(x, 10));
						putstr("; DEVICE = ");
						putstr(itoa(y, 10));
						putstr("; FUNCTION = ");
						putstr(itoa(z, 10));
						putstr(";\nBASE = 0x");
						putstr(itoa(base, 16));
						putstr("; SIZE = 0x");
						putstr(itoa(size, 16));
						putstr("; IRQ = ");
						putstr(itoa(data.IRQ_LINE, 10));
						putstr(".");
					}
				}
			}
		}
	}
}

//void hci_pci_init(uint8_t bus, uint8_t dev, uint8_ WOAH WOAH WOAH HOLD YOUR HORSES-- WE ONLY NEED UHCI SUPPORT FOR NOW. EHCI+ COMES LATER...
