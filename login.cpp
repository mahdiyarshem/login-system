#include <vector>

std::vector<User> users = {
    User("user1", "pass1", "skin1", 10),
    User("user2", "pass2", "skin2", 20)
};

User* login(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            return &user; // بازگشت اشاره‌گر به کاربر
        }
    }
    return nullptr; // اگر کاربر یافت نشد
}

void displayUserInfo(const User& user) {
    std::cout << "Login successful!\n";
    std::cout << "Username: " << user.username << "\n";
    std::cout << "Skin: " << user.skin << "\n";
    std::cout << "Playtime: " << user.playtime << " hours\n";
}

int main() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    User* loggedInUser = login(username, password);

    if (loggedInUser) {
        displayUserInfo(*loggedInUser);
    }
    else {
        std::cout << "Invalid username or password.\n";
    }

    return 0;
}