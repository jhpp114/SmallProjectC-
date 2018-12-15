#ifndef PHONE_H
#define PHONE_H
#include <iostream>

/*
    Get phone-number
    Get name of the User
    print phone number and user
*/
class Phone{
    friend std::ostream& operator<<(const std::ostream&, Phone&);
    friend std::istream& operator>>(std::istream&, Phone&);
    
    public:
        
    private:
        int phoneNumber;
        std::string name;
    
};

#endif //PHONE_H

