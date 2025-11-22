#include<iostream>
using namespace std;

class Combatant{
    string name;
    int id;
    int health;
    int attpower;
    public:
    Combatant(){
        name ="";
        id =0;
        health =0;
        attpower =0;
    }
    Combatant(string n,int i,int h,int ap){
        name =n;
        id =i;
        health =h;
        attpower =ap;
    }
    void setName(string n){name =n;}
    void setId(int i){ id =i;}
    void setHealth(int h){ health = h;}
    void setAttPower(int ap){ attpower = ap;}
    string getName(){ return name;}
    int getId(){ return id;}
    int getHealth(){ return health;}
    int getAttPower(){ return attpower;}
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Health: " << health << endl;
        cout << "Attack Power: " << attpower << endl;
    }
    void displayInline() {
       cout << name << " (ID:" << id << ", HP:" << health << ", AP:" << attpower << ")";
    }
    Combatant(const Combatant &obj) {
        name = obj.name;
        id = obj.id;
        health = obj.health;
        attpower = obj.attpower;
    }
    Combatant& operator=(const Combatant &obj) {
        if (this != &obj) { 
            name = obj.name;
            id = obj.id;
            health = obj.health;
            attpower = obj.attpower;
        }
        return *this;
    }
};
class Node
{
    public:
    Combatant data;
    Node *left;
    Node *right;
    Node(Combatant val):data(val){right=left=NULL;}

};
class Tree
{
    int count;
    Node*root;
    Node* insert(Node *node,Combatant val)
    {
        if(node==NULL){
            return new Node(val);
        }
        if(val.getId()<node->data.getId()){
            node->left=insert(node->left,val);
        }
        else if(val.getId()>node->data.getId()){
            node->right=insert(node->right,val);
        }
        return node;
    }
    public:
    Tree(){root=NULL;count=0;}
    void insert(Combatant val)
    {
        root=insert(root,val);
    }
    void inorder(Node *node)
    {
        if(node!=NULL){
            inorder(node->left);
            cout<<" ";
            node->data.displayInline();
            cout<<endl;
            inorder(node->right);
        } 
    }
    void display()
    {
        if(root==NULL){
            cout << "  [EMPTY - Team Defeated!]" << endl;
            return ;

        }
        inorder(root);
      
    }
    Node* findmin(Node *node)
    {
        while(node && node->left){
            node=node->left;
        }
        return node;
    }
    Node* Delete(Node *node,Combatant val)
    {
        if(node==NULL)return node;
         if(val.getId()<node->data.getId()){
            node->left=Delete(node->left,val);
        }
        else if(val.getId()>node->data.getId()){
            node->right=Delete(node->right,val);
        }
        else{
            if(node->left==NULL&&node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                Node *temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                Node *temp=node->left;
                delete node;
                return temp;
            }
            else{
                Node *temp=findmin(node->right);
                node->data=temp->data;
                node->right=Delete(node->right,temp->data);
            }
        }
        return node;
    }
    void  Delete(Combatant val)
    {
        root = Delete(root,val);
    }
    bool Search(int val){
        return Search(root,val);
    }
    bool Search(Node *node,int val)
    {
        if(node==NULL){
            return  false;
        }
        if(val==node->data.getId()){
            return true;
        }
        else if(val<node->data.getId()){
            return Search(node->left,val);
        }
        else
            return Search(node->right,val);
    }
    Combatant* getfrontline(){
        if(root == NULL){
            return NULL;
        }
        Node *temp = findmin(root);
        return &(temp->data);
    }
    bool isEmpty(){
        return root==NULL;
    }
     void updateHealth(int id, int newHealth) {
        updateHealthHelper(root, id, newHealth);
    }
    
    void updateHealthHelper(Node* node, int id, int newHealth) {
        if(node == NULL) return;
        if(id == node->data.getId()) {
            node->data.setHealth(newHealth);
            return;
        }
        else if(id < node->data.getId()) {
            updateHealthHelper(node->left, id, newHealth);
        }
        else {
            updateHealthHelper(node->right, id, newHealth);
        }
    }
};
class Game{
Tree players;
Tree Enemy;
int roundno;
public:
Game(){
    roundno=0;
    srand(time(0));
    initializeTeams();}
void initializeTeams(){
    cout << "   INITIALIZING BATTLEQUEST: BST ARENA" << endl;
    cout << "Creating Player's Team..." << endl;
        players.insert(Combatant("Warrior", 10, 100, 20));
        players.insert(Combatant("Mage", 5, 80, 25));
        players.insert(Combatant("Archer", 15, 90, 22));
        players.insert(Combatant("Paladin", 3, 120, 18));
        players.insert(Combatant("Rogue", 20, 85, 24));
        
        cout << "Creating Enemy Team..." << endl;
        Enemy.insert(Combatant("Goblin", 8, 70, 15));
        Enemy.insert(Combatant("Orc", 12, 95, 20));
        Enemy.insert(Combatant("Troll", 4, 110, 18));
        Enemy.insert(Combatant("Dragon", 25, 150, 25));
        Enemy.insert(Combatant("Skeleton", 2, 60, 12));
        
        cout << "\nTeams Initialized Successfully!\n" << endl;
}
void playerAttack(){
    Combatant* attacker=players.getfrontline();
    Combatant* defender=Enemy.getfrontline();
    if(defender==NULL || attacker ==NULL){
        return;
    }
    int damage = attacker->getAttPower()+(rand()%5);
    cout<<">>> "<<attacker->getName()<<" attacks "<<defender->getName()<<"!"<<endl;
    cout<<"    Demage Details:" <<damage<<" (Base: "<<attacker->getAttPower()<<
    " + Bonus: "<<damage - attacker->getAttPower()<<" )"<<endl;
    int newHealth = defender->getHealth()-damage;
    if(newHealth<=0){
        cout<<"\n    *** "<<defender->getName()<<" has been defeated! ***" <<endl;
        Combatant todelete=*defender;
        Enemy.Delete(todelete);
        if(!Enemy.isEmpty()) {
                Combatant* nextEnemy = Enemy.getfrontline();
                cout << "    " << nextEnemy->getName() << " steps forward as the new frontline!" << endl;
            }
        } else {
            Enemy.updateHealth(defender->getId(), newHealth);
    }
        cout << endl;

}
void Enemyattack(){
    Combatant* attacker=Enemy.getfrontline();
    Combatant* defender= players.getfrontline();
    if(defender==NULL || attacker ==NULL){
        return;
    }
    int damage = attacker->getAttPower()+(rand()%5);
    cout<<">>> "<<attacker->getName()<<" counterattacks "<<defender->getName()<<"!"<<endl;
    cout<<"    Demage Details:" <<damage<<" (Base: "<<attacker->getAttPower()<<
    " + Bonus: "<<damage - attacker->getAttPower()<<" )"<<endl;
    int newHealth = defender->getHealth()-damage;
    if(newHealth<=0){
        cout<<"\n    *** "<<defender->getName()<<" has been defeated! ***" <<endl;
        Combatant todelete=*defender;
        players.Delete(todelete);
        if(!players.isEmpty()) {
                Combatant* nextEnemy = players.getfrontline();
                cout << "    " << nextEnemy->getName() << " steps forward as the new frontline!" << endl;
            }
        } else {
            players.updateHealth(defender->getId(), newHealth);
    }
        cout << endl;
}
void startBattle() {
        cout << "\n========================================" << endl;
        cout << "        BATTLE!          " << endl;
        cout << "========================================\n" << endl;
        
        while(!players.isEmpty() && !Enemy.isEmpty()) {
            roundno++;
            cout << "|          ROUND " << roundno << " - BATTLE STATUS         |" << endl;
            cout << "\n--- PLAYER'S HEROES ---" << endl;
            players.display();
            cout << "\n--- ENEMY FORCES ---" << endl;
            Enemy.display();
        cout << endl;
            playerAttack();

            if(Enemy.isEmpty()) break;

            Enemyattack();
        
            if(players.isEmpty()) break;
            
            cout << "----------------------------------------" << endl;
        }
        cout << "\n========================================" << endl;
        cout << "          BATTLE CONCLUDED!" << endl;
        cout << "========================================\n" << endl;
        
        if(players.isEmpty()) {
            cout << "<<< DEFEAT! The enemy forces have won! >>>" << endl;
        } else {
            cout << "<<< VICTORY! Your heroes have made it ! >>>" << endl;
        }
        cout << "\nFinal Round: " << roundno << endl;
        cout << "\n========================================\n" << endl;
    }
};
int main(){
    Game battleQuest;
    battleQuest.startBattle();
    return 0;
}
