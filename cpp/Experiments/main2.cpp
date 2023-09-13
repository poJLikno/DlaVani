#include <iostream>

class SecretClass {
private:
    std::string token;
protected:
    void SetTokenTo(SecretClass& another) {
        another.token = token;
    }
public:
    SecretClass(const std::string& token) : token(token) {};
    std::string GetToken() const {
        return token;
    }
};

class MyClass : public SecretClass
{
public:
    MyClass(const std::string& token) : SecretClass(token) {}
    
    void SetValue(SecretClass& another) { SetTokenTo(another); }
};

void externalFunction(SecretClass& secret)
{
    MyClass obj("CODE");
    obj.SetValue(secret);
}

int main() {
    SecretClass secret("FUTURE");
    externalFunction(secret);
    std::cout << (secret.GetToken() == "CODE" ? "true" : "false") << '\n';
}
