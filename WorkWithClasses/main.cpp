#include <iostream>

class set{
    int *data;
    int size;
    int mem;
    public:
    set(){
    mem = 10;
    data = new int[mem];
    size = 0;
    }
    ~set() {
    delete[] data;
    }
    void add(int item) {
        for (int i = 0; i < size; i++) {
            if (data[i] == item) return;
        }
        if (mem <= size) {
            mem = mem * 2;
            int* newData = new int[mem];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;      
        }
        data[size] = item;
        size++;
    }
    set(const set& other) {
        size = other.size;
        mem = other.mem;
        data = new int[mem];
        for (int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
    set operator+(int item) {
        set result = *this; 
        result.add(item);  
        return result;      
    }
    set operator+(const set &g) {
        set result = *this; 
        for (int i = 0; i < g.size; i++){
            result.add(g.data[i]);  
        }
        return result;      
    }
    set operator*(const set &g){
        set result = set();
        for (int i = 0; i< g.size ;i++){
            for (int j = 0; j < size ;j++){
                if (g.data[i] == data[j]){
                    result.add(data[i]);
                    break;
                }
            }
        }
    return result;
    }
    void print(){
        std::cout << "{";
        for (int i=0; i<size; i++){
            std::cout << data[i];
        }
        std::cout << "}" << std::endl;
    }
};

class vehicle{
    int hp;
    int mass;
    char typeengine[20];
    static int totalHP; 
    public:
    static int getTotalHP() {  // геттер для статического поля
            return totalHP;
        }
    vehicle(int hp, int mass, char* engine) {
        this->hp = hp;
        this->mass = mass;
        for (int i=0;i<20;i++){
            this->typeengine[i]=engine[i];
        }
        totalHP += hp;
    }
    ~vehicle() {
        totalHP -= hp;
    }
    virtual void info() {
        std::cout << "Vehicle: " << hp << "hp, " << mass << "kg" << std::endl;
    }
    
    virtual void move() = 0; 
};
int vehicle::totalHP = 0;


class car : public vehicle{
    int doors;
public:
    car(int hp, int mass, char* engine, int doors) : vehicle(hp, mass, engine) {
    this->doors = doors;
    }

    void move() override {
    std::cout << "Car is driving" << std::endl;
    }

    void info() override {
        std::cout << "Car, doors: " << doors << std::endl;
    }
};
class ship : public vehicle{
    char type[20];
    public:
    ship(int hp, int mass, char* engine, char type[20]) : vehicle(hp,mass,engine){
        for (int i=0; i<20; i++){
            this->type[i]=type[i];
        }
    }
    void move() override {
    std::cout << "ship is sailing" << std::endl;
    }

    void info() override {
        std::cout << "type ship: " << type << std::endl;
    }
};

class plane : public vehicle{
    char typeplane[20];
    int engines;
    public:
    plane(int hp, int mass, char* engine, char typeplane[20], int engines):vehicle(hp, mass, engine){
        for (int i=0;i<20;i++){
            this->typeplane[i]=typeplane[i];
        }
        this->engines=engines;
    }
    void move() override {
        std::cout << "plane is flying"<<std::endl;
    }
    void info() override{
        std::cout << "type plane: " << typeplane << "  engines: " << engines << std::endl;
    }
};





int main(){
    char engine[] = "v4 16 value";
    car a(200, 1500, engine, 5);
    a.info();
    a.move();
    
    char engine2[] = "diesel";
    ship b(300, 5000, engine2, "cargo");
    b.info();
    b.move();
    
    char engine3[] = "jet";
    char planetype[] = "boeing";
    plane c(1000, 20000, engine3, planetype, 4);
    c.info();
    c.move();
    
    std::cout << "Total HP: " << vehicle::getTotalHP() << std::endl;
    
    return 0;
}

