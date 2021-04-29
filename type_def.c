#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	Car
{
	char	*engine;
	char	*fuel_type;
	int		fuel_tank_cap;
	int		seating_cap;
	float	city_mileage;
} Car;

int		main()
{
	Car	car1;
	Car	car2;

	car1.fuel_tank_cap = 45;
	car2.fuel_tank_cap = 38;
	printf("%d\n%d\n", car1.fuel_tank_cap, car2.fuel_tank_cap);
}
