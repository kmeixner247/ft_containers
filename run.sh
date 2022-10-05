# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 23:14:39 by kmeixner          #+#    #+#              #
#    Updated: 2022/10/05 23:20:15 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

c++ -Wall -Werror -Wextra -std=c++98 ./tests/vector_tests.cpp && leaks --atExit -- ./a.out
c++ -Wall -Werror -Wextra -std=c++98 ./tests/map_tests.cpp && leaks --atExit -- ./a.out
c++ -Wall -Werror -Wextra -std=c++98 ./tests/stack_tests.cpp && leaks --atExit -- ./a.out
c++ -Wall -Werror -Wextra -std=c++98 ./tests/set_tests.cpp && leaks --atExit -- ./a.out