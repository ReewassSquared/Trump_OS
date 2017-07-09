~/barebones-toolchain/setenv.sh
cd ..

i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/main.c -o obj/main.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/vga/scrnlib.c -o obj/scrnlib.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/gdt.c -o obj/gdt.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/idt.c -o obj/idt.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/irq.c -o obj/irq.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/isrs.c -o obj/isrs.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/drivers/timer.c -o obj/timer.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/drivers/keyboard.c -o obj/keyboard.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/command/cmd.c -o obj/cmd.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/IO/ports.c -o obj/ports.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/string.c -o obj/string.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/echo.c -o obj/echo.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/help.c -o obj/help.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/vga/menu.c -o obj/menu.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/debug.c -o obj/debug.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/debug/vars.c -o obj/vars.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/calc.c -o obj/calc.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/screencolor.c -o obj/screencolor.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/fontcolor.c -o obj/fontcolor.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/get.c -o obj/get.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/listcolor.c -o obj/listcolor.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/commands/trumpphrase.c -o obj/trumpphrase.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c lib32/rand.c -o obj/rand.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/drivers/rtc.c -o obj/rtc.o
i686-elf-gcc -ffreestanding -Wall -Wextra -fno-builtin -nostdinc -I./include -std=gnu99 -nostdlib  -c kernel/IO/pci.c -o obj/pci.o
nasm -f elf32 ASM/start.asm -o obj/start.o
i686-elf-gcc -Wall -Wextra -ffreestanding -nostdlib -lgcc -T compile/linker.ld -o trumpos.img obj/start.o obj/string.o obj/main.o obj/scrnlib.o obj/gdt.o obj/idt.o obj/irq.o obj/isrs.o obj/timer.o obj/keyboard.o obj/cmd.o obj/ports.o obj/echo.o obj/help.o obj/menu.o obj/debug.o obj/vars.o obj/calc.o obj/screencolor.o obj/fontcolor.o obj/get.o obj/listcolor.o obj/trumpphrase.o obj/rand.o obj/rtc.o obj/pci.o
cd compile
