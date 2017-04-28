#ifndef PCI_H
#define PCI_H
#include <system.h>

#define USB_CLASS_CODE 0x0C
#define USB_SUBCLASS_CODE 0x03

struct __attribute__ ((packed)) PCI_POSITION //stores the position of a controller and a few important locations for it.
{
	uint8_t BUS;
	uint8_t DEVICE;
	uint8_t FUNCTION;
	uint8_t IRQ_LINE;
	uint32_t BASE;
	uint32_t SIZE;
};

struct __attribute__ ((packed)) PCI_CONFIG
{					//OFFSET:
	uint16_t VENDOR_ID; 		//0x00
	uint16_t DEVICE_ID;          	//0x02
	uint16_t COMMAND_REG; 		//0x04
	uint16_t STATUS_REG;		//0x06
	uint8_t REVISION_ID;		//0x08
	uint8_t PROGRAMMING_INTERFACE;	//0x09
	uint8_t SUBCLASS_CODE;		//0x0A
	uint8_t CLASS_CODE;		//0x0B
	uint8_t CACHE_LINE_SIZE;	//0x0C
	uint8_t LATENCY_TIMER;		//0x0D
	uint8_t HEADER_TYPE;		//0x0E
	uint8_t SELF_TEST;		//0x0F
	uint32_t BAR0; 			//0x10	//BAR = BASE ADDRESS REGISTER; used with OHCI, EHCI and xHCI
	uint32_t BAR1;			//0x14
	uint32_t BAR2;			//0x18
	uint32_t BAR3;			//0x1C
	uint32_t BAR4; 			//0x20	//used with the UHCI <-- Y U GOTTA B DIFRINT
	uint32_t BAR5;			//0x24
	uint32_t CARDBUS_CIS_PTR;	//0x28
	uint16_t SUBSYS_VENDOR_ID; 	//0x2C	//SUBSYS = SUBSYSTEM
	uint16_t SYBSYS_ID;		//0x2E
	uint32_t EXPANSION_ROM_BA;	//0x30	//BA = BASE ADDRESS
	uint8_t CAPABILITIES_OFFSET;	//0x34
	uint8_t RESERVED_0[3];		//0x35
	uint32_t RESERVED_1;		//0x38
	uint8_t IRQ_LINE;		//0x3C
	uint8_t INTERRUPT_PIN;		//0x3D
	uint8_t MINIMUM_TIME;		//0x3E
	uint8_t MAXIMUM_LATENCY;	//0x3F
	uint32_t VARIED_VALUES[48];	//0x40 to 0xFF
}; 

extern unsigned int read_pci(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset, const uint8_t length);
extern void write_pci(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset, const uint8_t length, const uint32_t write);
extern unsigned int pci_memory_range(const uint8_t bus, const uint8_t dev, const uint8_t func, const uint8_t port_offset);
extern void search_for_usb_controllers();

#endif
