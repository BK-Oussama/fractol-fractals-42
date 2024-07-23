


#include <stdlib.h>
#include <stdio.h>


// int	ft_isspace(int c)
// {
// 	if ((c >= 9 && c <= 13) || c == ' ')
// 		return (c);
// 	return (0);
// }


// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (c);
// 	return (0);
// }


// static int	skip_space_sign(char *str, int *is_neg)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_isspace(str[i]))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			*is_neg *= -1;
// 		i++;
// 	}
// 	return (i);
// }


// double	ft_atof(char *str)
// {
// 	int		i;
// 	double	nb;
// 	int		is_neg;
// 	double	div;

// 	nb = 0;
// 	div = 0.1;
// 	is_neg = 1;
// 	i = skip_space_sign(str, &is_neg);
// 	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
// 	{
// 		nb = (nb * 10.0) + (str[i] - '0');
// 		i++;
// 	}
// 	if (str[i] == '.')
// 		i++;
// 	while (str[i] && ft_isdigit(str[i]))
// 	{
// 		nb = nb + ((str[i] - '0') * div);
// 		div *= 0.1;
// 		i++;
// 	}
// 	if (str[i] && !ft_isdigit(str[i]))
// 		return (-42);
// 	return (nb * is_neg);
// }

//////////////////////////////////////////////////////////


#include <stdio.h>
#include <ctype.h>

double ft_atof(const char *str) {
    // Initialize variables
    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    int divisor = 1;
    int decimal_count = 0;

    // Skip leading whitespaces
    while (isspace(*str)) {
        str++;
    }

    // Handle sign
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Process integral and fractional parts
    while (*str) {
        if (isdigit(*str)) {
            if (decimal_count) {
                fraction = fraction * 10.0 + (*str - '0');
                divisor *= 10;
            } else {
                result = result * 10.0 + (*str - '0');
            }
        } else if (*str == '.' && decimal_count == 0) {
            decimal_count++;
        } else {
            break; // Stop processing on non-numeric character
        }
        str++;
    }

    // Combine integer and fractional parts
    result += fraction / divisor;

    // Apply sign
    result *= sign;

    return result;
}

// // Example Usage
// int main() {
//     const char *str1 = "  -123.456";
//     const char *str2 = "3.14159";
//     const char *str3 = "42.0";
//     const char *str4 = "0.00123";
//     const char *str5 = "-0.75";
//     const char *str6 = "12.34.56"; // Invalid: multiple decimals
//     const char *str7 = "abc123";   // Invalid: leading non-numeric

//     printf("String: \"%s\" -> Float: %lf\n", str1, ft_atof(str1));
//     printf("String: \"%s\" -> Float: %lf\n", str2, ft_atof(str2));
//     printf("String: \"%s\" -> Float: %lf\n", str3, ft_atof(str3));
//     printf("String: \"%s\" -> Float: %lf\n", str4, ft_atof(str4));
//     printf("String: \"%s\" -> Float: %lf\n", str5, ft_atof(str5));
//     printf("String: \"%s\" -> Float: %lf\n", str6, ft_atof(str6)); // Invalid input test
//     printf("String: \"%s\" -> Float: %lf\n", str7, ft_atof(str7)); // Invalid input test

//     return 0;
// }





int main(int argc, char **argv)
{
	double db = atof(argv[1]);
	double db2 = ft_atof(argv[1]);
//	argc(void
	printf("STD__Result=====>:\t%f\n", db);
	printf("OUR__Result----->:\t%f\n", db2);

	return 0;
}
