
//______________________________________________________OOP_________________________________________________

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Banckaccount {
    private:
        string accountnumber;// رقم الحساب 
        string ownername;    // اسم صاحب الحساب
    protected:    
        double balance;      // الرصيد
    public:
        Banckaccount(string accnum,string ownm,double bal){
            setaccountnumber(accnum);
            setownername(ownm);
            setbalance(bal);

        }   
        void deposit(double amount){
            if(amount>0){
                balance += amount;
            }
        } 
        virtual void withdraw(double amount){
            if(amount<=balance){
                balance -= amount;
            }
        }
        virtual void printDetails(){
            cout<<"Account Number : "<<getaccountnumber()<<endl;
            cout<<"Owner Name : "<<getownername()<<endl;
            cout<<"Balance : "<<getbalance()<<endl;
        }
        void setaccountnumber(string accnum){
            accountnumber = accnum;
        }
        string getaccountnumber(){
            return accountnumber;
        }
        void setownername(string ownm){
            ownername = ownm;
        }
        string getownername(){
            return ownername;
        }
        void setbalance(double bal){
            balance = bal;
        }
        double getbalance(){
            return balance;
        }
};

class SavingsAccount : public Banckaccount{
    private:
        double interestRate;
    public:
        SavingsAccount(string accnum,string ownm,double bal,double intrate) : Banckaccount(accnum,ownm,bal) {
            setinterestRate(intrate);
        }
        void applyInterest(){
            Banckaccount::balance += (interestRate * balance); 
        }   
        void printDetails() override{
            Banckaccount::printDetails();
            cout<<"INTEREST RATE : "<<getinterestRate()<<endl;
            
        }

        void setinterestRate(double intrate){
            interestRate = intrate;
        }
        double getinterestRate(){
            return interestRate;
        }

};

class CheckingAccount : public Banckaccount{
    private:
        double overdraftLimit;
    public:
        CheckingAccount(string accnum,string ownm,double bal,double limit) : Banckaccount(accnum,ownm,bal){
            setoverdraftLimit(limit);
        }
        void withdraw(double amount) override{
            if(amount <= (Banckaccount::balance + getoverdraftLimit())){
                Banckaccount::balance -= amount;
            }
        }  
        void printDetails() override{
            Banckaccount::printDetails();
            cout<<"Overdraft : "<<getoverdraftLimit()<<endl;
            
        }
        void setoverdraftLimit(double lim){
            overdraftLimit = lim;
        }  
        double getoverdraftLimit(){
            return overdraftLimit;
        }
};

class Customer{
    private:
        string name;
        vector<Banckaccount*> accounts;
    public:
        Customer(string n){
            setname(n);
        }
        void addAccount(Banckaccount* acc){
            accounts.push_back(acc);
        }
        void printAllAccounts(){
            for(int i=0;i<accounts.size();i++){
                cout<<"____________________________________________"<<endl;
                accounts[i]->printDetails(); // طباعة بيانات الحساب طبقا لنوعه 

            }
        }
        void setname(string n){
            name = n;
        }
        string getname(){
            return name;
        }
};
int main()
{
    Customer c("Mostafa");
    SavingsAccount s1("00123455","Mostafa Gamal",10000,0.05);
    CheckingAccount c1("00123456","Mostafa Gamal",5000,6000);
    c.addAccount(&s1);
    c.addAccount(&c1);
    c.printAllAccounts();
    return 0;
}
// Final version to upload