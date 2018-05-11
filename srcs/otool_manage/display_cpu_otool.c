#include "otool_manage.h"
#include <mach-o/fat.h>
#include "utilities.h"

void    display_cpu(char *name, int cpu_type)
{
	ft_putstr(name);
	if (cpu_type == CPU_TYPE_POWERPC)
		ft_putstr(" (architecture ppc):\n");
	else if (cpu_type == CPU_TYPE_X86)
		ft_putstr(" (architecture i386):\n");
	else if (cpu_type == CPU_TYPE_X86_64)
		ft_putstr(" (architecture X86_64):\n");
	else
	{
		ft_putstr(" (unkown architecture : ");
		ft_putnbr(cpu_type);
		ft_putstr(")\n");
	}
}
