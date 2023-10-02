#ifndef JOS_INC_ELF_H
#define JOS_INC_ELF_H

#define ELF_MAGIC 0x464C457FU	/* "\x7FELF" in little endian */

struct Elf {
	uint32_t e_magic;	 // 0  // must equal ELF_MAGIC
	uint8_t e_elf[12];   // 4
	uint16_t e_type;	 // 10
	uint16_t e_machine;  // 
	uint32_t e_version;    // 14
	uint32_t e_entry;      // 18 
	uint32_t e_phoff;      // 1c 
	uint32_t e_shoff;      // 20  
	uint32_t e_flags;      // 24
	uint16_t e_ehsize;     // 28
	uint16_t e_phentsize;  // 
	uint16_t e_phnum;	   // 2c 
	uint16_t e_shentsize;  // 
	uint16_t e_shnum;      // 30 
	uint16_t e_shstrndx;
};

struct Proghdr { // 32字节
	uint32_t p_type;    // 0
	uint32_t p_offset;  // 04
	uint32_t p_va;      // 08
	uint32_t p_pa;      // 0c
	uint32_t p_filesz;  // 10
	uint32_t p_memsz;   // 14
	uint32_t p_flags;   // 18
	uint32_t p_align;   // 1c 
};

struct Secthdr { //40字节， 0x28
	uint32_t sh_name;
	uint32_t sh_type;
	uint32_t sh_flags;
	uint32_t sh_addr;
	uint32_t sh_offset;
	uint32_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint32_t sh_addralign;
	uint32_t sh_entsize;
};

// Values for Proghdr::p_type
#define ELF_PROG_LOAD		1

// Flag bits for Proghdr::p_flags
#define ELF_PROG_FLAG_EXEC	1
#define ELF_PROG_FLAG_WRITE	2
#define ELF_PROG_FLAG_READ	4

// Values for Secthdr::sh_type
#define ELF_SHT_NULL		0
#define ELF_SHT_PROGBITS	1
#define ELF_SHT_SYMTAB		2
#define ELF_SHT_STRTAB		3

// Values for Secthdr::sh_name
#define ELF_SHN_UNDEF		0

#endif /* !JOS_INC_ELF_H */
