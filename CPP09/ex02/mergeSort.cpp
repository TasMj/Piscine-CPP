/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:08:50 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/12 00:27:06 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"
#include <queue>

/*
1) diviser en 2 chaque bloc jusqu'a otenir des blocs de 1
2) compare n et n + 1 pour les remettre dans l'ordre dans le bloc de 2 precedent.
3) comparer le premier du bloc avec le 2 eme du bloc pour le placer dans le bloc du dessus
et ainsi de suite.
si

2 7  -  5 9
comparer 2 et 5
puis 7 et 5

2
7   -   5 9

2 5
7   -   9

2 5 7 9

et ainsi de suite
*/
