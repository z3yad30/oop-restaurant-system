#include <iostream>
using namespace std ;
class order ;
class restaurant
{
private :
    struct menu
    {
        string dish[100] , categry[100] , discribtion[100] ;
        float price[100] ;
        int stock[100] ;
        int numOfdishes , menuid ;
    }; menu z1[100] ;
    int tnumOfdishes = 0 , numOfmenus ;
    static int menu_id ;
public :
    void add_menu() ;
    void edit_menu() ;
    void delete_menuitems() ;
    void display_menu() ;
    restaurant(){ cout << "welcome to ITPG restaurant\n" ; }
    friend class order ;
};
class order /// : public restaurant
{
private :
    struct order_items
    {
        int orderid , stock_ordered[100] , numOdishes ;
        string dish_ordered[100] , name_costumer ;
        float totalberorder ;
    };
    order_items z2[100] ;
    int numOforders = 0 , cridet_id ;
    float total ;
    static int order_id ;
    int discount[5] = { 1234 , 5678 , 987 , 654 , 321 } ;
public :
    restaurant z3 ;        /// <-- focus here...
    void get_order() ;
    void edit_order() ;
    void remove_order() ;
    void payment() ;
    void discount_total() ;
};
void help( restaurant z ) ;
void help2( order z1 ) ;
int restaurant::menu_id = 1000 ;
int order::order_id = 962300000 ;
int main()   /// main function...
{
    /// restaurant z ;
    /// help( z );
    /// z.add_menu();
    order z1 ;
    z1.z3.add_menu();
    z1.get_order();
    /// z1.help2( z1 ) ;
}
void order::discount_total()
{
    cout << "enter your discount code : " ;
    int test , r ;
    cin >> test ;
    for ( int i = 1 ; i <= 5 ; i++ )
    {
        if ( test == discount[i] )
        {
            r++ ;
            cout << "here you 10LE as a discount\nthanks\n" ;
            break ;
        }
    }
    if ( r == 0 )
        cout << "sorry, this discount code not founded\n" ;
    cout << "want to try again? : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "yes" && answer != "no" )
    {
        cout << "[ yes , no ] : " ;
        cin >> answer ;
    }
    if ( answer == "yes" )
        discount_total() ;
    else{
        cout << "thanks\nvisit us again\n" ;
    }
}
void order::payment()
{
    cout << "hello sir\n" ;
    for ( int i = 1 ; i <= numOforders ; i++ )
    {
        cout << "order with id : " << z2[i].orderid << " total coast is : " << z2[i].totalberorder ;
        cout << endl ;
    }
    cout << "that means that total coast is : " << total ;
    cout << "how you want to pay : " ;
    string answer2 ;
    cin >> answer2 ;
    while ( answer2 != "cash" && answer2 != "credit" )
    {
        cout << "invalid entering, renter please\n" ;
        cout << "[ cash , credit ] : " ;
        cin >> answer2 ;
    }
    if ( answer2 == "cash" )
    {
        cout << "thanks, visit us again please\n" ;
    }
    else{
        cout << "enter your credit id : " ;
        cin >> cridet_id ;
        cout << "thanks, visit us again please\n" ;
    }
    /// any thing else...
    cout << "any thing else : " ;
    string s ;
    cin >> s ;
    while ( s != "discount" && s != "end" )
    {
        cout << "invalid entering\n" ;
        cout << "[ discount , end ] : " ;
        cin >> s ;
    }
    if ( s == "discount" )
    {
        discount_total() ;
    }
    else {
        cout << "thanks\nvisit us again\n" ;
    }
}
void order::remove_order()
{
    /// <-
        cout << "enter the id of the menu you want to delete : " ;
    int answer3 ;
    cin >> answer3 ;
    int s = 0 ;
    for ( int i = 1 ; i <= numOforders ; i++ )
    {
        if ( z2[i].orderid == answer3 )
        {
            s = i ;
            break ;
        }
    }
    if ( s > 0 )
    {
        cout << "founded successfully\n" ;
        for ( int i = 1 ; i <= s ; i++ )
        {
            z2[s].dish_ordered[i] = " " ;
            z2[s].name_costumer = " " ;
            z2[s].stock_ordered[i] = 0 ;
            total - z2[s].totalberorder ;
            z2[s].totalberorder = 0 ;
            z2[s].numOdishes = 0 ;
        }
        cout << "order deleted successfully\n" ;
    }
    else{
        cout << "can't find this order, sorry\n" ;
    }
    /// any thing else...
    cout << "any thing else : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "new" && answer != "edit" && answer != "delete"
           && answer != "pay" )
    {
        cout << "invalid entering, choice:\n" ;
        cout << "[ new , edit , delete , pay ] : " ; ////
        cin >> answer ;
    }
    if ( answer == "new" )
        get_order();
    if ( answer == "edit" )
        edit_order();
    if ( answer == "delete" )
        remove_order() ;
    if ( answer == "pay" )
        payment();
}
void order::edit_order()
{
    cout << "enter the id of the menu you want to edit : " ;
    int answer3 ;
    cin >> answer3 ;
    int s = 0 ;
    for ( int i = 1 ; i <= numOforders ; i++ )
    {
        if ( z2[i].orderid == answer3 )
        {
            s = i ;
            break ;
        }
    }
    if ( s > 0 )
    {
        cout << "founded successfully, start enter your order again:\n" ;
        for ( int i = 1 ; i <= z2[s].numOdishes ; i++ )
        {
            cout << "dish number " << i << " is : " ;
            cin >> z2[s].dish_ordered[i] ;
            for ( int y = 1 ; y <= 100 ; y++ )
            {
            for ( int x = 1 ; x <= 100 ; x++ )
            {
                if ( z2[s].dish_ordered[i] == z3.z1[y].dish[x] )
                {
                    cout << "founded successfully\n" ;
                    cout << "enter the stock you want : " ;
                    cin >> z2[s].stock_ordered[i] ;
                    while ( z2[s].stock_ordered[i] > z3.z1[y].stock[x] )
                    {
                        cout << "the stock must be less than " << z3.z1[y].stock[x] ;
                        cin >> z2[s].stock_ordered[i] ;
                    }
                    float d = z3.z1[y].price[x] * z2[s].stock_ordered[i] ;
                    z2[s].totalberorder += d ;
                    total += d ;
                }
            }
            }
        }
    }
    else {
        cout << "can't find this menu, sorry\n" ;
    }
    /// any thing else...
    cout << "any thing else : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "new" && answer != "edit" && answer != "delete"
           && answer != "pay" )
    {
        cout << "invalid entering, choice:\n" ;
        cout << "[ new , edit , delete , pay ] : " ; ////
        cin >> answer ;
    }
    if ( answer == "new" )
        get_order();
    if ( answer == "edit" )
        edit_order();
    if ( answer == "delete" )
        remove_order() ;
    if ( answer == "pay" )
        payment();
}
void order::get_order()
{
    order_id ++ ;
    numOforders ++ ;
    cout << "starting taking the order\n" ;
    z2[numOforders].orderid = order_id ;
    cout << "enter your name please : " ;
    cin >> z2[numOforders].name_costumer ;
    /// getline( cin , z2[numOforders].name_costumer );
    cout << "new order will be with id [ " << z2[numOforders].orderid ;
    cout << " ] how many dishes you want to order : ";
    int answer2 ;
    cin >> answer2 ;
    for ( int i = 1 ; i <= answer2 ; i++ )
    {
        cout << "dish number " << i << " name is : " ;
        cin >> z2[numOforders].dish_ordered[i] ;
        for ( int y = 1 ; y <= 100 ; y++ )
        {
            for ( int x = 1 ; x <= 100 ; x++ )
            {
                if ( z2[numOforders].dish_ordered[i] == z3.z1[y].dish[x] )
                {
                    cout << "founded successfully\n" ;
                    cout << "enter the stock you want : " ;
                    cin >> z2[numOforders].stock_ordered[i] ;
                    while ( z2[numOforders].stock_ordered[i] > z3.z1[y].stock[x] )
                    {
                        cout << "the stock must be less than " << z3.z1[y].stock[x] << " , renter : " ;
                        cin >> z2[numOforders].stock_ordered[i] ;
                    }
                    float d = z3.z1[y].price[x] * z2[numOforders].stock_ordered[i] ;
                    z2[numOforders].totalberorder += d ;
                    total += d ;
                }
            }
        }
    }
    cout << "thanks\n" ;
    cout << "any thing else : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "new" && answer != "edit" && answer != "delete"
           && answer != "pay" )
    {
        cout << "invalid entering, choice:\n" ;
        cout << "[ new , edit , delete , pay ] : " ; ////
        cin >> answer ;
    }
    if ( answer == "new" )
        get_order();
    if ( answer == "edit" )
        edit_order();
    if ( answer == "delete" )
        remove_order() ;
    if ( answer == "pay" )
        payment();
}
void restaurant::display_menu()
{
    cout << "now representing the menus:\n" ;
    for( int i = 1 ; i <= numOfmenus ; i++ )
    {
        cout << "listed under menu with id : " << z1[i].menuid << " : \n" ;
        for ( int y = 1 ; y <= z1[i].numOfdishes ; y++ )
        {
            cout << y << ") " << z1[i].dish[y] << " with price : " << z1[i].price[y] << "\n" ;
            cout << " with stock : " << z1[i].stock[y] << " category : " << z1[i].categry << endl ;
            cout << "note : " << z1[i].discribtion[y] << endl ;
        }
    }
    cout << "tanks\n" ;
    cout << "any thing else? : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "add" && answer != "edit" && answer != "delete"
           && answer != "print" && answer != "end" )
    {
        cout << "invalid entering choice from:\n" ;
        cout << "[ add , edit , delete , print , end ] : " ;
        cin >> answer ;
    }
    if ( answer == "add" )
        add_menu();
    if ( answer == "edit" )
        edit_menu();
    if ( answer == "delete" )
        delete_menuitems() ;
    if ( answer == "print" )
    {
        display_menu() ;
    }
    if ( answer == "end" )
        cout << "thanks\n" ;
}
void restaurant::delete_menuitems()
{
    cout << "enter the id of the menu you want to delete : " ;
    int answer1 ;
    cin >> answer1 ;
    int menu_number ;
    for ( int i = 1 ; i <= numOfmenus ; i++ )
    {
        if ( z1[i].menuid == answer1 )
        {
            menu_number = i ;
        }
    }
    for ( int i = 1 ; i <= z1[menu_number].numOfdishes ; i++ )
    {
        z1[menu_number].dish[i] = "deleted" ;
        z1[menu_number].categry[i] = "deleted" ;
        z1[menu_number].discribtion[i] = "deleted" ;
        z1[menu_number].price[i] = 0 ;
        z1[menu_number].stock[i] = 0 ;
    }
    cout << "deleted successfully\n" ;
    cout << "any thing else? : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "add" && answer != "edit" && answer != "delete"
           && answer != "print" && answer != "end" )
    {
        cout << "invalid entering choice from:\n" ;
        cout << "[ add , edit , delete , print , end ] : " ;
        cin >> answer ;
    }
    if ( answer == "add" )
        add_menu();
    if ( answer == "edit" )
        edit_menu();
    if ( answer == "delete" )
        delete_menuitems() ;
    if ( answer == "print" )
    {
        display_menu() ;
    }
    cout << "thanks\n" ;
}
void restaurant::edit_menu()
{
    cout << "enter the id of the menu you want to edit : " ;
    int answer1 ;
    cin >> answer1 ;
    int menu_number ;
    for ( int i = 1 ; i <= numOfmenus ; i++ )
    {
        if ( z1[i].menuid == answer1 )
        {
            menu_number = i ;
        }
    }
    cout << "renter the data of this menu\n" ;
    for ( int i = 1 ; i <= z1[menu_number].numOfdishes ; i++ )
    {
        cout << "dish " << i << " : " ;
        /// getline ( cin , z1[menu_number].dish[i] );
        cin >> z1[menu_number].dish[i];
        cout << "discribtion : " ;
        /// getline( cin , z1[menu_number].discribtion[i] );
        cin >> z1[menu_number].discribtion[i];
        cout << "category : " ;
        /// getline ( cin , z1[menu_number].categry[i] );
        cin >> z1[menu_number].categry[i];
        cout << "price : " ;
        cin >> z1[menu_number].price[i] ;
        cout << "stock : " ;
        cin >> z1[menu_number].stock[i] ;
    }
    cout << "tanks\n" ;
    cout << "any thing else? : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "add" && answer != "edit" && answer != "delete"
           && answer != "print" && answer != "end" )
    {
        cout << "invalid entering choice from:\n" ;
        cout << "[ add , edit , delete , print , end ] : " ;
        cin >> answer ;
    }
    if ( answer == "add" )
        add_menu();
    if ( answer == "edit" )
        edit_menu();
    if ( answer == "delete" )
        delete_menuitems() ;
    if ( answer == "print" )
    {
        display_menu() ;
    }
    if ( answer == "end" )
        cout << "thanks\n" ;
}
void restaurant::add_menu()
{
    cout << "how many menus you want to add : " ;
    int x ;
    cin >> x ;
    numOfmenus += x ;
    for ( int i = 1 ; i <= x ; i++ )
    {
        menu_id ++ ;
        z1[i].menuid = menu_id ;
        cout << "menu with id " << z1[i].menuid << " cereated\n" ;
        cout << "how many dishes this menu have : " ;
        cin >> z1[i].numOfdishes ;
        tnumOfdishes += z1[i].numOfdishes ;
        cout << "start enter the data of this menu : \n" ;
        for( int y = 1 ; y <= z1[i].numOfdishes ; y++ )
        {
            cout << "name dish " << y << " : " ;
            /// getline ( cin , z1[i].dish[y] );
            cin >> z1[i].dish[y] ;
            cout << "discribtion : " ;
            /// getline( cin , z1[i].discribtion[y] );
            cin >> z1[i].discribtion[y];
            cout << "category : " ;
            /// getline ( cin , z1[i].categry[y] );
            cin >> z1[i].categry[y];
            cout << "price : " ;
            cin >> z1[i].price[y] ;
            cout << "stock : " ;
            cin >> z1[i].stock[y] ;
        }

    }
    cout << "thanks\n" ;
    cout << "any thing else? : " ;
    string answer ;
    cin >> answer ;
    while ( answer != "add" && answer != "edit" && answer != "delete"
           && answer != "print" && answer != "end" )
    {
        cout << "invalid entering choice from:\n" ;
        cout << "[ add , edit , delete , print , end  ] : " ;
        cin >> answer ;
    }
    if ( answer == "add" )
        add_menu();
    if ( answer == "edit" )
        edit_menu();
    if ( answer == "delete" )
        delete_menuitems() ;
    if ( answer == "print" )
    {
        display_menu() ;
    }
    if ( answer == "end" )
        cout << "thanks\n" ;
}
