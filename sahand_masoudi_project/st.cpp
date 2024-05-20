#include <bits\stdc++.h>
#include "clui.h"
using namespace std;
map<string, int> mp;
set<string> ms;
set<string> ss;
#define KeyUP 72
#define KeyDO 80
#define KeyLE 75
#define KeyRI 77
set<pair<int, string>> se;
char ch = 'd', newch = 'd', ch2 = 80;
int row = 20, col = 40, length1 = 4, point1 = 0, length2 = 4, point2 = 0, sp, xx = 5, kk = 4, l;
char z = 60;
string username1, username2, newusername;
struct loc
{
    int y;
    int x;
};
int check(loc head1, int endgamecond, loc array1[], int currentlen1, loc bomb, loc array2[], int currentlength2, loc head2)
{
    // check clash snake1 & wall
    if (head1.x == 0 || head1.x == col - 1 || head1.y == 0 || head1.y == row - 1)
    {
        return 0;
    }
    // check clash snake1 with  body
    for (int j = 1; j < currentlen1; j++)
    {
        if (head1.x == array1[j].x && head1.y == array1[j].y)
        {
            return 0;
        }
    }

    // check clash snake1 with bomb
    if (((head1.x == bomb.x) && (head1.y == bomb.y)))
    {
        return 0;
    }

    // check clash snake2 with wall
    if (head2.x == 0 || head2.x == col - 1 || head2.y == 0 || head2.y == row - 1)
    {
        return 0;
    }
    // check clash with snake2Head &snake2 body
    for (int s = 1; s < currentlength2; s++)
    {
        if ((array2[0].x == array2[s].x) && (array2[0].y == array2[s].y))
        {
            return 0;
        }
    }
    // check clash snake2 & bomb
    if (((head2.x == bomb.x) && (head2.y == bomb.y)))
    {
        return 0;
    }
    // check clash snake1Head and snake2 body
    for (int i = 0; i < length2 + point2; i++)
        if ((array1[0].x == array2[i].x) && (array1[0].y == array2[i].y))
        {
            return 0;
        }
    // check clash snake2Head and snake1 body
    for (int i = 0; i < length1 + point1; i++)
        if ((head2.x == array1[i].x) && (head2.y == array1[i].y))
        {
            return 0;
        }
    return endgamecond;
}
void Print(loc ar1[], loc sib, loc bomb, loc ar2[])
{
    int a = 0;
    for (int j = 0; j < row; ++j)
    {
        for (int c = 0; c < 20; c++)
            cout << " ";
        change_color_rgb(242, 238, 0);
        cout << "#";
        reset_color;
        for (int i = 0; i < col; i++)
        {
            a = 0;
            if (j == 0 || j == row - 1)
            {
                change_color_rgb(242, 238, 0);
                cout << "#";
                reset_color;
            }
            else
            {
                for (int u = 0; u < length1 + point1; u++)
                {
                    if (j == ar1[u].y && i == ar1[u].x)
                    {
                        change_color_rgb(33, 218, 255);
                        if (u == 0)
                            cout << "B";
                        else
                        {
                            cout << "b";
                        }
                        a = 1;
                        reset_color;
                    }
                }
                for (int v = 0; v < length2 + point2; v++)
                {
                    if (j == ar2[v].y && i == ar2[v].x)
                    {
                        change_color_rgb(75, 255, 69);
                        if (v == 0)
                            cout << "O";
                        else
                        {
                            cout << "o";
                        }
                        a = 1;
                        reset_color;
                    }
                }
                if (sib.x == i && sib.y == j && a != 1)
                {
                    change_color_rgb(242, 0, 255);
                    cout << "A";
                    a = 1;
                    reset_color;
                }
                else if (bomb.x == i && bomb.y == j && a != 1)
                {
                    change_color_rgb(255, 0, 0);
                    cout << "X";
                    a = 1;
                    reset_color;
                }
                else if (a != 1)
                    cout << " ";
            }
        }
        change_color_rgb(242, 238, 0);
        cout << "#";
        reset_color;
        cout << endl;
    }
    cout << endl;
    change_color_rgb(179, 25, 255);
    cout << (*ss.begin()) << "...." << point1 << endl
         << endl;
    cout << (*ss.rbegin()) << "...." << point2 << endl;
    reset_color();
}
void update(loc array1[], char ch, int emtiaz1)
{
    switch (ch)
    {
    case 'w':
        for (int i = 1; i < length1 + emtiaz1; i++)
        {

            array1[length1 + emtiaz1 - i] = array1[length1 + emtiaz1 - i - 1];
        }
        (array1[0].y)--;
        break;

    case 's':
        for (int i = 1; i < length1 + emtiaz1; i++)
        {

            array1[length1 + emtiaz1 - i] = array1[length1 + emtiaz1 - i - 1];
        }
        (array1[0].y)++;
        break;

    case 'd':
        for (int i = 1; i < length1 + emtiaz1; i++)
        {
            array1[length1 + emtiaz1 - i] = array1[length1 + emtiaz1 - i - 1];
        }
        (array1[0].x)++;
        break;

    case 'a':
        for (int i = 1; i < length1 + emtiaz1; i++)
        {

            array1[length1 + emtiaz1 - i] = array1[length1 + emtiaz1 - i - 1];
        }
        (array1[0].x)--;
        break;
    }
}
void update2(char ch2, int emtiaz2, loc array2[])
{
    switch (ch2)
    {
    case 72:

        for (int i = 1; i < length2 + emtiaz2; i++)
        {

            array2[length2 + emtiaz2 - i] = array2[length2 + emtiaz2 - i - 1];
        }
        (array2[0].y)--;
        break;

    case 80:

        for (int i = 1; i < length2 + emtiaz2; i++)
        {

            array2[length2 + emtiaz2 - i] = array2[length2 + emtiaz2 - i - 1];
        }
        (array2[0].y)++;
        break;

    case 77:

        for (int i = 1; i < length2 + emtiaz2; i++)
        {
            array2[length2 + emtiaz2 - i] = array2[length2 + emtiaz2 - i - 1];
        }
        (array2[0].x)++;
        break;

    case 75:

        for (int i = 1; i < length2 + emtiaz2; i++)
        {

            array2[length2 + emtiaz2 - i] = array2[length2 + emtiaz2 - i - 1];
        }
        (array2[0].x)--;
        break;

    default:
        break;
    }
}
loc bombloc(loc &bomb, loc array1[], loc apple, loc array2[])
{
    int f = 1;
    while (f)
    {
        bomb.x = rand() % (col - 1);
        bomb.y = rand() % (row - 1);
        for (int i = 0; i < length1 + point1; ++i)
            if (array1[i].x == bomb.x && array1[i].y == bomb.y)
            {
                f = 1;
                continue;
            }
        for (int i = 0; i < length2 + point2; ++i)
            if (array2[i].x == bomb.x && array2[i].y == bomb.y)
            {
                f = 1;
                continue;
            }
        if ((bomb.x == apple.x) && (bomb.y == apple.y))
        {
            f = 1;
            continue;
        }
        f = 0;
    }
    return bomb;
}
int checkApplePosition(loc array1[], loc apple, loc array2[], loc bomb)
{
    int r = 0;
    for (int i = 0; i < length1 + point1; ++i)
        if (array1[i].x == apple.x && array1[i].y == apple.y)
            r = 1;
    for (int i = 0; i < length2 + point2; ++i)
        if (array2[i].x == apple.x && array2[i].y == apple.y)
            r = 1;
    if ((bomb.x == apple.x) && (bomb.y == apple.y))
        r = 1;
    if (apple.x == 0 || apple.y == 0)
        r = 1;
    return r;
}
void appleLoc(loc &apple, loc array1[], loc array2[], loc bomb)
{
    srand(time(NULL));
    int cond = 1;
    while (cond)
    {
        apple.x = rand() % (col - 1);
        apple.y = rand() % (row - 1);
        cond = checkApplePosition(array1, apple, array2, bomb);
    }
}
void increaseLength(int &point1, loc &apple, loc array1[], loc array2[], int &point2, loc bomb)
{
    if ((array1[0].x == apple.x) && (array1[0].y == apple.y))
    {
        point1++;
        mp[username1]++;
        apple.x = 120;
        apple.y = 120;
        appleLoc(apple, array1, array2, bomb);
    }
    if ((array2[0].x == apple.x) && (array2[0].y == apple.y))
    {
        point2++;
        mp[username2]++;
        apple.x = 120;
        apple.y = 120;
        appleLoc(apple, array1, array2, bomb);
    }
}
void menutwo()
{
    {
        clear_screen();
        change_color_rgb(0, 153, 255);
        cout << "Please enter first username" << endl
             << endl;
        cout << "first username : ";
        cin >> username1;
        ms.insert(username1);
        ss.insert(username1);
        mp[username1] = 0;
        cout << endl
             << endl;
        cout << "Please enter second username" << endl
             << endl;
        cout << "second username : ";
        cin >> username2;
        mp[username2] = 0;
        ms.insert(username2);
        ss.insert(username2);
        clear_screen();
        cout << "please select game speed" << endl
             << endl;
        cout << "1 ) Fast" << endl
             << endl;
        cout << "2 ) Medium" << endl
             << endl;
        cout << "3 ) Slow" << endl
             << endl;
        int o = 1;

        while (o)
        {
            sp = getch();
            if (sp == 49 || sp == 50 || sp == 51)
                o = 0;
        }
        if (sp == 1)
            sp = 0;
        if (sp == 2)
            sp = 50;
        if (sp == 3)
            sp = 100;
        reset_color();
    }
}
void menu2()
{
    clear_screen();
    for (int i = 0; i < 20; i++)
        cout << " ";
    cout << "game Hint" << endl;
    cout << endl;
    change_color_rgb(75, 255, 69);
    cout << "Snake 1 : " << endl
         << endl;
    cout << "<w> for up" << endl
         << endl;
    cout << "<a> for go left" << endl
         << endl;
    cout << "<s> for down" << endl
         << endl;
    cout << "<d> for go right" << endl
         << endl;
    cout << endl
         << endl;
    reset_color();
    change_color_rgb(33, 218, 255);
    cout << "Snake 2 : " << endl
         << endl;
    cout << "<flashUp> botton for up" << endl
         << endl;
    cout << "<flashLeft> botton for go left" << endl
         << endl;
    cout << "<flashDown> botton for down" << endl
         << endl;
    cout << "<flashRight> botton for go right" << endl
         << endl;
    delay(10000);
    reset_color();
    clear_screen();
}
void menu3()
{
    clear_screen();
    change_color_rgb(0, 153, 255);
    cout << (*ss.begin()) << "...." << point1 << endl
         << endl;
    cout << (*ss.rbegin()) << "...." << point2 << endl
         << endl;
    if (point1 > point2)
        cout << endl
             << (*ss.begin()) << "   WIN" << endl;
    else if (point1 < point2)
        cout << (*ss.rbegin()) << " WIN" << endl;
    if (point1 == point2)
        cout << "DRAW";
    delay(8000);
    reset_color();
}
void mainmenu()
{
    change_color_rgb(0, 153, 255);
    clear_screen();
    cout << "1 ) START GAME" << endl;
    cout << "2 ) POINTS TABLE" << endl;
    cout << "3 ) ADD USERS" << endl;
    cout << "4 ) EXIT" << endl;
}
int endgamecond = 1;
void game()
{
    menu2();
    point1 = 0;
    point2 = 0;
    ch = 'd', newch = 'd', ch2 = 80;
    loc array1[100] = {{5, 5}, {5, 4}, {5, 3}, {5, 2}};
    loc *start = array1;
    for (int i = 4; i < 100; i++)
    {
        array1[i].x = 120;
        array1[i].y = 120;
    }
    loc array2[100] = {{2, 1}, {2, 2}, {2, 3}, {2, 4}};
    for (int i = 4; i < 100; i++)
    {
        array2[i].x = 300;
        array2[i].y = 300;
    }
    loc apple = {3, 4};
    loc bomb = bombloc(bomb, array1, apple, array2);
    clear_screen();
    point1 = 0;
    point2 = 0;
    while (endgamecond)
    {
        Print(array1, apple, bomb, array2);
        if (kbhit())
        {
            newch = getch();
        }
        if (newch == 'w' || newch == 'd' || newch == 's' || newch == 'a')
            if (abs(int(newch) - int(ch)) != 4 && abs(int(newch) - int(ch)) != 3)
            {
                ch = newch;
                update(array1, ch, point1);
            }
            else
            {
                update(array1, ch, point1);
            }
        else
        {
            update(array1, ch, point1);
        }
        if (int(newch) == KeyDO || int(newch) == KeyUP || int(newch) == KeyLE || (newch) == KeyRI)
        {
            if (fabs(int(newch) - int(ch2)) != 2 && fabs(int(newch) - int(ch2)) != 8)
            {
                ch2 = newch;
                update2(ch2, point2, array2);
            }
            else
            {
                update2(ch2, point2, array2);
            }
        }
        else
        {
            update2(ch2, point2, array2);
        }
        increaseLength(point1, apple, array1, array2, point2, bomb);
        endgamecond = check(array1[0], endgamecond, array1, point1 + length1, bomb, array2, length2 + point2, array2[0]);
        cursor_to_pos(0, 0);
        delay(sp);
    }
    delay(5000);
    menu3();
}
void mainmenufun()
{
    cin >> xx;
    if (xx > 4 || xx < 1)
    {
        cout << "please enter true number";
        int p = 1;
        while (p)
        {
            cin >> xx;
            if (xx <= 4 && xx >= 1)
                p = 0;
        }
    }
    if (xx == 1)
    {
        endgamecond = 1;
    }
    else if (xx == 2)
    {
        set<string> mscopy;
        cout << "Number of players : " << ms.size() << endl;
        while (ms.size() > 0)
        {
            mscopy.insert((*ms.begin()));
            se.insert({mp[(*ms.begin())], (*ms.begin())});
            ms.erase((*ms.begin()));
        }
        while (mscopy.size() > 0)
        {
            ms.insert((*mscopy.begin()));
            mscopy.erase((*mscopy.begin()));
        }
        int ind = 1;
        while (se.size() > 0)
        {
            cout << ind << "   :    " << (*se.rbegin()).second << " " << (*se.rbegin()).first << endl;
            ind++;
            se.erase((*se.rbegin()));
        }
        cout << endl
             << endl;
        cout << "do you want to continue playing game?" << endl;
        cout << endl;
        cout << "1 ) yes" << endl;
        cout << "2 ) no" << endl;
        while (kk > 3)
            cin >> kk;
        if (kk == 2)
        {
            cout << "Thankyou for playing";
            xx = 4;
        }
        if (kk == 1)
            endgamecond = 1;
    }
    else if (xx == 3)
    {
        change_color_rgb(33, 218, 255);
        cout << "what player you want to change" << endl;
        cout << "1 ) username1" << endl
             << endl;
        cout << "2 ) username2" << endl
             << endl;
        cin >> l;
        cout << "please enter new username" << endl;
        cin >> newusername;
        if (l == 1)
        {
            ss.erase(username1);
            username1 = newusername;
            ms.insert(username1);
            ss.insert(username1);
            mp[username1];
        }
        if (l == 2)
        {
            ss.erase(username2);
            username2 = newusername;
            ms.insert(username2);
            ss.insert(username2);
            mp[username2];
        }
        endgamecond = 1;
    }
    else if (xx == 4)
    {
        cout << "Thankyou for playing!" << endl;
        xx = 4;
    }
    if (!(xx == 2 && kk == 2) && !(xx == 4))
    {
        endgamecond = 1;
        game();
        mainmenu();
        xx = 5;
        kk = 4;
    }
}
int main()
{
    clear_screen();
    change_color_rgb(0, 153, 255);
    cout << "Snake Game" << endl
         << endl
         << "Hi" << endl
         << endl;
    cout << "1 ) START" << endl
         << endl
         << "2 ) EXIT" << endl;
    reset_color();
    int oo = 1;
    while (oo)
    {
        z = getch();
        if (z == 49)
        {
            menutwo();
            oo = 0;
        }
        if (z == 50)
        {
            oo = 0;
            return 0;
        }
    }
    game();
    mainmenu();
    while (xx - 4)
    {
        mainmenufun();
    }
    return 0;
}
