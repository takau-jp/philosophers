/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:17:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/01/17 22:28:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_ctx			ctx;
	t_settings		settings;
	t_simulation	simulation;

	if (parse_arguments(argc, argv, &settings) == false)
		return (EXIT_FAILURE);
	ft_bzero(&ctx, sizeof(t_ctx));
	if (init_ctx(&ctx, &settings, &simulation) == false)
		return (EXIT_FAILURE);
	simulate_philos(&ctx, settings.n_philos, &simulation);
	clear_ctx(&ctx, settings.n_philos);
	return (EXIT_SUCCESS);
}
