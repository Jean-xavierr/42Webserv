#include "parse_conf.hpp"

/*
 * This program take the first letter of a key word and forward the iterator to
 * the next first letter of the next key word.
 * 
 * Example 1
 * Gived :
 * |
 * root /www; index index.html;
 * 
 * Result :
 * root /www; index index.html;
 *            |
 * 
 * Example 2
 * Gived :
 * |
 * root /www; }
 * 
 * Result :
 * root /www; }
 *            |
 */

static void    skip_location(t_strcit &it) {
    while (*it != '}')
        ++it;
    ++it;
    while (is_space(*it))
        ++it;
}

void    skip_param(t_strcit &it) {
    if (get_word_it(it) == "location") {
        skip_location(it);
        return ;
    }
    while (*it != ';' && *it != '}')
        ++it;
    if (*it == ';') // skip "; "
        it += 2;
}

/*
int         main(int argc, char **argv) {
    std::string arg(argv[1]);
    std::string::iterator it = arg.begin();

    std::cout << arg << std::endl;
    skip_param(it);

    std::string af_skip(it, arg.end());
    std::cout << af_skip << std::endl;
    return (0);
}
*/
