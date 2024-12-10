#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int rows{5};
int columns{7};

void print_message(const std::string &msg) // qui affiche un message
{                                          
    std::cout << msg;
}

void reset_board(std::vector<std::vector<char>> &tbl)
{
    tbl = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '.'));
}

void print(std::vector<std::vector<char>> tbl)
{
    for (std::vector<char> i : tbl)
    {
        for (char j : i)
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void add_snake_to_board(std::vector<std::vector<char>> &tbl, std::vector<std::vector<int>> &snake)
{
    tbl[snake[0][0]][snake[0][1]] = 'O';
    for (int k = 1; k < snake.size(); k++)
    {
        tbl[snake[k][0]][snake[k][1]] = 'o';
    }
}

void generate_apple(std::vector<int> &p, const std::vector<std::vector<int>> snake)
{
    p = {rand() % rows, rand() % columns};
    int cpt {};
    while (cpt<=snake.size())    //pour que la pomme n'apparaisse pas sur le serpent
    {
        for (std::vector<int> coord : snake) {
            if (p==coord) {
                p = {rand() % rows, rand() % columns};
                cpt = 0;
            }
        cpt+=1;
        }
    }
}


void add_apple_to_board(std::vector<std::vector<char>> &tbl, std::vector<int> &p)
{
    tbl[p[0]][p[1]] = '@';
}


int main()
{
    // Création d'un élément board
    std::vector<std::vector<char>> board;

    // Création du serpent au milieu
    int i{rows/2}; //renvoie bien un entier car divison d'entiers
    int j{columns/2-1};
    std::vector<std::vector<int>> snake{{}, {}, {}};
    for (int k = 0; k < 3; k++)
    {
        snake[k] = {i, j};
        j += 1;
    }

    // Création d'un élément pomme
    std::vector<int> apple;
    generate_apple(apple, snake);


    // Le jeu est alors une boucle sans fin qui:
    //   - attend que le joueur tape sur une touche
    //   - fait l'action demandée
    //   - et recommence ou échoue.

    // Le caractère pour stocker la clé qui sera entrée au clavier.
    char key;
    while (true)
    {
        reset_board(board);               // on réinitialise le board
        add_apple_to_board(board, apple); // on ajoute la pomme au board
        add_snake_to_board(board, snake); // on ajoute le serpent au board
        print(board);                     // on affiche le board
        print_message("what do you want to do ('q' to quit):");

        std::cin >> key; // on attend que l'utilisateur entre un caractère au clavier
        if (key)
        {
            if ((key == 'i') or (key == 'k') or (key == 'j') or (key == 'l'))
            {
                int ny;
                int nx;
                std::vector<int> np;    //nouvelles coord de la tete
                std::vector<int> last; //dernier vecteur de snake

                if (key == 'i')
                {
                    ny = snake[0][0] - 1;
                    nx = snake[0][1];
                    np = {ny, nx};
                    last = snake[snake.size()-1];
                    if (nx < 0 or nx > columns - 1 or ny < 0 or ny > rows - 1)  // si on sort du board
                    { 
                        print_message("bye bye !\n");
                        exit(0);
                    }
                    for (std::vector<int> coord : snake)    // si on se mange
                    { 
                        if (np == coord)
                        {
                            print_message("bye bye!\n");
                            exit(0);
                        }
                    }
                    for (int k = snake.size() - 1; k > 0; k--)  // on deplace le snake
                    {
                        snake[k] = snake[k - 1];
                    }
                    snake[0] = np;
                    if (np==apple) //on mange une pomme
                    {
                        snake.push_back(last);
                        generate_apple(apple, snake);
                    }
                }

                if (key == 'k')
                {
                    ny = snake[0][0] + 1;
                    nx = snake[0][1];
                    np = {ny, nx};
                    last = snake[snake.size()-1];
                    if (nx < 0 or nx > columns - 1 or ny < 0 or ny > rows - 1)
                    { 
                        print_message("bye bye !\n");
                        exit(0);
                    }
                    for (std::vector<int> coord : snake)
                    { 
                        if (np == coord)
                        {
                            print_message("bye bye!\n");
                            exit(0);
                        }
                    }
                    for (int k = snake.size() - 1; k > 0; k--)
                    { 
                        snake[k] = snake[k - 1];
                    }
                    snake[0] = np;
                    if (np==apple) //on mange une pomme
                    {
                        snake.push_back(last);
                        generate_apple(apple, snake);
                    }
                }

                if (key == 'j')
                {
                    ny = snake[0][0];
                    nx = snake[0][1] - 1;
                    np = {ny, nx};
                    last = snake[snake.size()-1];
                    if (nx < 0 or nx > columns - 1 or ny < 0 or ny > rows - 1)
                    { 
                        print_message("bye bye !\n");
                        exit(0);
                    }
                    for (std::vector<int> coord : snake)
                    { 
                        if (np == coord)
                        {
                            print_message("bye bye!\n");
                            exit(0);
                        }
                    }
                    for (int k = snake.size() - 1; k > 0; k--)
                    {
                        snake[k] = snake[k - 1];
                    }
                    snake[0] = np;
                    if (np==apple) //on mange une pomme
                    {
                        snake.push_back(last);
                        generate_apple(apple, snake);
                    }
                }

                if (key == 'l')
                {
                    ny = snake[0][0];
                    nx = snake[0][1] + 1;
                    np = {ny, nx};
                    last = snake[snake.size()-1];
                    if (nx < 0 or nx > columns - 1 or ny < 0 or ny > rows - 1)
                    {
                        print_message("bye bye !\n");
                        exit(0);
                    }
                    for (std::vector<int> coord : snake)
                    { 
                        if (np == coord)
                        {
                            print_message("bye bye!\n");
                            exit(0);
                        }
                    }
                    for (int k = snake.size() - 1; k > 0; k--)
                    {
                        snake[k] = snake[k - 1];
                    }
                    snake[0] = np;
                    if (np==apple) //on mange une pomme
                    {
                        snake.push_back(last);
                        generate_apple(apple, snake);
                    }
                }

            }
            else if (key == 'q')
            {
                print_message("bye bye !\n");
                exit(0); // l'utilisateur demande à quitter le jeu
            }
        }
    }
    return 0;
}
