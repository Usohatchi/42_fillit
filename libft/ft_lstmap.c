/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:54:37 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 16:06:54 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	ret = malloc(sizeof(t_list));
	ret = (*f)(lst);
	ret->next = ft_lstmap(lst->next, (*f));
	return (ret);
}
