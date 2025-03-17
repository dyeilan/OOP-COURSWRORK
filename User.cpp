#include "User.h"
#include <string>

USER::USER(int id, std::string Name, std::string email_address, std::string pass_word, std::string account_type)
    : userID(id), Name(Name), email_address(email_address), pass_word(pass_word), account_type(account_type) {}

USER::~USER() {} // Virtual destructor implementation

bool USER::LOGIN(std::string input_email, std::string input_pass) {
    int count = 0;
    int email_check = 0;
    for (int i = 0; i < input_email.size(); i++) {
        if (i < email_address.size() && input_email[i] == email_address[i]) email_check++;
    }
    if (email_check == input_email.size() && email_check == email_address.size()) count++;
    int pass_check = 0;
    for (int j = 0; j < input_pass.size(); j++) {
        if (j < pass_word.size() && input_pass[j] == pass_word[j]) pass_check++;
    }
    if (pass_check == input_pass.size() && pass_check == pass_word.size()) count++;
    if (count == 2) {
        if (input_email == email_address && input_pass == pass_word) return true;
    }
    return false;
}

std::string USER::get_acc_type() {
    std::string temp_type = account_type;
    return temp_type;
}

int USER::GetUserID() const {
    int temp_id = userID;
    return temp_id;
}

std::string USER::getName() {
    std::string temp_name = Name;
    return temp_name;
}

std::string USER::getEmail() {
    std::string temp_email = email_address;
    return temp_email;
}