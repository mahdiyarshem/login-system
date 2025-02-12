#include <fstream>

void saveUsersToFile(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& user : users) {
        file << user.username << " " << user.password << " " << user.skin << " " << user.playtime << "\n";
    }
    file.close();
}

void loadUsersFromFile(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);
    std::string username, password, skin;
    int playtime;

    while (file >> username >> password >> skin >> playtime) {
        users.push_back(User(username, password, skin, playtime));
    }
    file.close();
}

int main() {
    std::vector<User> users;
    loadUsersFromFile(users, "users.txt");

    // عملیات لاگین و نمایش اطلاعات

    saveUsersToFile(users, "users.txt"); // ذخیره تغییرات
    return 0;
}