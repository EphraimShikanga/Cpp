#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string spinWords(const std::string &str)
{
    std::istringstream iss(str); // create individual words from string
    std::ostringstream oss;      // create a string from the individual words
    std::string word;
    bool first = true;

    while (iss >> word)
    {
        if (word.length() >= 5)
        {
            std::reverse(word.begin(), word.end());
        }
        if (!first)
        {
            oss << " ";
        }

        oss << word;
        first = false;
    }

    return oss.str();
}

int main()
{
    std::cout << spinWords("alive are I dont like pizza interesting and are are I eat I Mainly many pizza not still interesting eat pizza many Mainly Tomatos is pizza many are could or is foods kinds dont are they Tomatos pizza dont dont am I eat wish like wish interesting is are kinds love pizza because not forever not CODEWARS many I eat wish dont like CODEWARS alive forever interesting used eat or Mainly am for love good kinds are I forever wish good not making interesting is interesting am I kinds or pizza used I while dont I of they interesting or like of am and still and dont used for love CODEWARS because are making are pizza love many for am pizza I alive could many for many I I CODEWARS pizza many still making pizza they are love because used interesting I pizza pizza I kinds not not used are foods of kinds still used am not because still forever wish making for I like alive many kinds for eat I and alive I for interesting pizza pizza alive for for good forever dont many are alive I Mainly for pizza are Tomatos am could and I making wish are are wish dont dont good Mainly still making are for or is not like I while still alive spaghetti many Mainly are they foods eat kinds kinds for I and many is foods kinds Mainly good am I Tomatos I kinds Tomatos are or used foods I interesting interesting used alive is wish is eat like foods pizza and Tomatos Mainly forever wish am or love of many could is of like making alive forever could kinds forever while foods Tomatos love interesting pizza and pizza many many forever foods still because good am used I still many dont good they many many Mainly Mainly Mainly are I good I interesting foods foods Mainly kinds still interesting for is spaghetti or wish good many pizza for am pizza dont and are making kinds not Tomatos eat are because Tomatos love are eat many or pizza dont pizza foods dont for is kinds for of many because is because not Mainly I pizza interesting are Tomatos kinds pizza pizza I pizza interesting I interesting pizza good or many and alive while not I not good used for wish I am dont I am Tomatos used foods I interesting making forever am good they like pizza for I because are and eat pizza for I while are pizza am spaghetti dont interesting is alive good spaghetti because because or of pizza are forever they still and Mainly I good many still pizza still I spaghetti are or like pizza wish many still wish CODEWARS not for interesting for while eat of kinds or eat CODEWARS pizza pizza pizza alive because kinds spaghetti pizza because or pizza while forever love dont used I I dont love Tomatos pizza eat making interesting pizza is kinds pizza interesting spaghetti or while pizza could is foods of or making I many for pizza forever kinds spaghetti could pizza pizza pizza Mainly are kinds Mainly I are good used am making used Mainly wish used are spaghetti love eat kinds making spaghetti because Mainly are I CODEWARS CODEWARS because love Mainly still Tomatos interesting eat are good I I or I I I foods eat because good could are is CODEWARS used pizza dont I making I while I for pizza could while or pizza I pizza") << std::endl;
    // std::cout << spinWords("This is a test") << std::endl;
    // std::cout << spinWords("This is another test") << std::endl;
    // std::cout << spinWords("You are almost to the last test") << std::endl;
    // std::cout << spinWords("Just kidding there is still one more") << std::endl;
    // std::cout << spinWords("Seriously this is the last one") << std::endl;
    return 0;
}