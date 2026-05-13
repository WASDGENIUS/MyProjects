#include <iostream>

template <typename T>
class set{
    T *data;
    int size;
    int mem;
    public:
    set(){
    mem = 10;
    data = new T[mem];
    size = 0;
    }
    ~set() {
    delete[] data;
    }
    void add(T item) {
        for (int i = 0; i < size; i++) {
            if (data[i] == item) return;
        }
        if (mem <= size) {
            mem = mem * 2;
            T* newData = new T[mem];
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
        data = new T[mem];
        for (int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
    set operator+(T item) {
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
    void printAll(){
        std::cout << "{" << std::endl;
        for (int i = 0; i < size; i++){
            data[i]->print();
        }
        std::cout << "}" << std::endl;
    }
};

class vehicle{
    protected:
    int hp;
    int mass;
    char typeengine[20];
    static int totalHP; 
    public:
    static int getTotalHP(){
            return totalHP;
        }
    vehicle(int hp, int mass, const char* engine) {
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
    virtual void print() {
        std::cout << "hp:" << hp << " mass:" << mass << std::endl;
    }
    vehicle(){
        hp=0;
        mass=0;
        typeengine[0] = ' ';
    }
    
    virtual void move() = 0; 

    bool operator==(vehicle &other){
        return mass==other.mass && hp==other.hp;
    }
};
int vehicle::totalHP = 0;


class car : public vehicle{
    int doors;
public:
    car(int hp, int mass, const char* engine, int doors) : vehicle(hp, mass, engine) {
    this->doors = doors;
    }
    car(){
        doors = 0;
    }

    void move() override {
    std::cout << "Car is driving" << std::endl;
    }

    void print() override {
        std::cout << "Car, doors: " << doors << " hp: " << hp << " mass: " << mass << std::endl;;
    }
};
class ship : public vehicle{
    char type[20];
    public:
    ship(int hp, int mass, const char* engine, const char type[20]) : vehicle(hp,mass,engine){
        for (int i=0; i<20; i++){
            this->type[i]=type[i];
        }
    }
    ship(){
        type[0] = ' ';
    }
    void move() override {
    std::cout << "ship is sailing" << std::endl;
    }

    void print() override {
        std::cout << "type ship: " << type << " hp: " << hp << " mass: " << mass << std::endl;
    }
};

class plane : public vehicle{
    char typeplane[20];
    int engines;
    public:
    plane(int hp, int mass, const char* engine, const char typeplane[20], int engines):vehicle(hp, mass, engine){
        for (int i=0;i<20;i++){
            this->typeplane[i]=typeplane[i];
        }
        this->engines=engines;
    }
    plane(){
        typeplane[0]= ' ';
        engines = 0;
    }
    void move() override {
        std::cout << "plane is flying"<<std::endl;
    }
    void print() override{
        std::cout << "type plane: " << typeplane << " engines: " << engines << " hp: " << hp << " mass: " << mass << std::endl;
    }
};





int main(){

    set<int> nums1;
    nums1.add(1); 
    nums1.add(2); 
    nums1.add(3);
    
    set<int> nums2;
    nums2.add(2); 
    nums2.add(3); 
    nums2.add(4);
    
    set<int> plus = nums1 + nums2;
    set<int> crossed = nums1 * nums2;
    
    nums1.print();
    plus.print();
    crossed.print();
    
    set<char> chars;
    chars.add('a'); 
    chars.add('b'); 
    chars.add('c');
    chars.print();
  

    car a(200, 1500,"v4", 5);
    plane b(1600, 2300,"v16","kukuruznik", 2);
    ship c(5500, 30000, "v56", "titanic");

    set<vehicle*> mixed;
    mixed.add(&a);
    mixed.add(&b);
    mixed.add(&c);
    mixed.printAll();
    std::cout << "total hp: " << vehicle::getTotalHP() << std::endl;
    return 0;
}

