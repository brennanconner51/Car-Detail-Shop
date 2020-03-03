#include <iostream>
#include <windows.h>

/* this is a junk program for my GF's old car detailing job. the idea being that they would have been able to use
 * it every day /week/ whatever to get the results of the days revenue and have the program do all the math for them.
 * The shop closed down so obviously it will never get used but I wanted a spot where I could practice. The program is written 
 * in C++ since that's what I have been studying. Eventually I plan to add in more to help this grow into what could have been
 * a full functional program they could have run every/week/month/year to tally up all the sales and blah blah blah.
 * I'm sure a lot of this could be viewed as sloppy code for sure so if you somehow stumble accross this please try not to be
 * too harsh. 

int main() {

    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	/*pricing for variables/contants/etc*/

    int cars_detailed {0};
    int SUVs_detailed {0};
    int mtrcls_detailed {0};
	double price_car{ 36.95 };
	double price_SUV{ 41.65 };
	double price_mtrcls{ 15.35 };
	double tax{ 0.06 };
	double daily_shop{ 250.0 };
	double supply_percar{ 5.5 };
	double supply_perSUV{ 7.25 };
	double supply_permtrcls{ 2.75 };
    
    
	/*User input for daily vehicles*/

    std::cout << " Welcome to the daily income calculator" << std::endl;
    std::cout << std::endl;
    std::cout << "Lets get started! How many cars did you detail today? " << std::endl;
    std::cin >> cars_detailed;
    std::cout << "Awesome! How many SUV's did you detail today?" << std::endl;
    std::cin >> SUVs_detailed;
    std::cout << "Fantastic! Did you detail any motorcycles today? " << std::endl;
    std::cin >> mtrcls_detailed;
    
    double daily_car_total = (cars_detailed * price_car) +(SUVs_detailed * price_SUV) + (mtrcls_detailed * price_mtrcls);
    double daily_car_tax = ( (cars_detailed * price_car) + (SUVs_detailed * price_SUV) + (mtrcls_detailed * price_mtrcls) ) * tax;
    double daily_supply_total = (cars_detailed * supply_percar) + (SUVs_detailed * supply_perSUV) + (mtrcls_detailed * supply_permtrcls);
    double daily_supply_tax = ( (cars_detailed * supply_percar) + (SUVs_detailed * supply_perSUV) + (mtrcls_detailed * supply_permtrcls) ) * tax; 

	/*Output for the resulting revenue*/

    std::cout << "**************************************************************" << std::endl;
    std::cout << "Awesome! Here is the daily sumary of earnings and supplies cost!!" << std::endl;
    std::cout << "\nGross Revenue from Cars:  $" << cars_detailed * price_car << std::endl;
    std::cout << "\nGross Revenue from SUV's : $" << SUVs_detailed * price_SUV << std::endl;
    std::cout << "\nGross Revenue from Motorcycles : $" << mtrcls_detailed * price_mtrcls << std::endl;
    std::cout << "**************************************************************"<< std::endl;
    std::cout << "Here is the daily cost and inventory" << std::endl;
    std::cout << "\nTotal number of vehicles cleaned : " << (cars_detailed + SUVs_detailed + mtrcls_detailed) << std::endl;
    std::cout << "\nIncome from total vehicles : $" << daily_car_total << std::endl;
    std::cout << "\nIncome tax from total vehicles : $" << daily_car_tax << std::endl;
    std::cout << "\nSupply cost : $" << daily_supply_total << std::endl;
    std::cout << "\nSupply cost Tax : $" << daily_supply_tax << std::endl;
    std::cout << "\nEnd of day total income : $" << (daily_car_total + daily_car_tax) - (daily_supply_total + daily_supply_tax + daily_shop) << std::endl;
    std::cout << "\nBe sure to Copy these records to your daily revenue sheet before closing!!" <<std::endl;
    return 0;
}
