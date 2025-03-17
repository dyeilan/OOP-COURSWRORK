#ifndef USER_H
#define USER_H
#include <string>

class USER {
private:
    int userID;
    std::string Name, email_address, pass_word, account_type;
public:
    USER(int id, std::string Name, std::string email_address, std::string pass_word, std::string account_type);
    virtual ~USER(); // Added virtual destructor for polymorphism
    bool LOGIN(std::string input_email, std::string input_pass);
    std::string get_acc_type();
    int GetUserID() const;
    std::string getName();
    std::string getEmail();
};

#endif