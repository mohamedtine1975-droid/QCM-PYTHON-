#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

// ============================================
// STRUCTURES DE DONNÉES
// ============================================

// Structure pour représenter un utilisateur
struct Utilisateur{
    int id;
    char nom[30];           // CORRECTION: ajout de la taille du tableau
    char prenom[30];
    char email[35];
    char password[30];
    char role[20];          // CORRECTION: char[] au lieu de char simple
    Utilisateur* suivant;   // Pointeur vers l'utilisateur suivant (liste chaînée)
};

// Structure pour représenter un produit
struct Produit{
    int idProduit;
    int quantiteStock;
    char nomProduit[35];    // CORRECTION: char[] au lieu de char simple
    float prix;
    Produit* suivant;       // Pointeur vers le produit suivant
};

// Structure pour représenter une commande
struct Commande{
    int idCommande;
    int idUtilisateur;      // CORRECTION: renommé de 'id' pour clarté
    char dateCom[20];
    float montantTotal;
    Commande* suivant;      // AJOUT: pour liste chaînée
};

// Structure pour représenter un produit dans le panier
struct ProduitPanier{
    int idProduit;
    char nomProduit[35];    // CORRECTION: char[] au lieu de char simple
    int quantite;
    float prix;
    ProduitPanier* suivant; // Pointeur vers le produit suivant
};

// ============================================
// CLASSES DE GESTION DES LISTES
// ============================================

class ListeMonoUtilisateur{
public:                     // CORRECTION: public pour accès aux méthodes
    Utilisateur* tete;      // CORRECTION: public pour accès direct
    int taille;

    // Constructeur
    ListeMonoUtilisateur() {
        tete = nullptr;
        taille = 0;
    }
    
    // Méthodes de gestion
    void ajouter(int id, char nom[], char prenom[], char email[], char password[], char role[]);
    void afficherTous();
    void sauvegarderFichier();
    bool seConnecter(char email[], char password[], char role[]);
    void modifierUtilisateur(char email[]);
    void supprimerUtilisateur(char nomUtil[]);
};

class ListeMonoProduit{
public:                     // CORRECTION: public pour accès aux méthodes
    Produit* tete1;         // CORRECTION: public pour accès direct
    int taille1;

    // Constructeur
    ListeMonoProduit() {
        tete1 = nullptr;
        taille1 = 0;
    }
    
    // Méthodes de gestion
    void ajouterProduit(int idProduit, char nomProduit[], float prix, int quantiteStock);
    void afficherTousProduit();
    void modifierProduit(char nomProduit[]);
    void supprimerProduit(char nomProd[]);
    void sauvegarderFichierProduit();
};

class ListeMonoProduitPanier{
public:                     // CORRECTION: public pour accès aux méthodes
    ProduitPanier* tete3;   // CORRECTION: public pour accès direct
    int taille2;

    // Constructeur
    ListeMonoProduitPanier(){
        tete3 = nullptr;
        taille2 = 0;
    }
    
    // Méthodes de gestion
    void ajouterProduitPanier(int idProduit, char nomProduit[], float prix, int quantite);
    void afficherTousProduitPanier();
    void modifierQuantitePanier(char nomProduit[]);
    void supprimerProduitPanier(int position);
    void viderPanier();
};

// ============================================
// PROTOTYPES DES FONCTIONS D'AFFICHAGE MENUS
// ============================================
// CORRECTION: retournent int au lieu de void

int afficherMenuProgramme();
int afficherMenuAdmin();
int GestionUtilisateur();
int GestionProduit();
int afficherMenuPanier();
int afficherMenuClient();
int afficherCommande();

// ============================================
// PROTOTYPES DES FONCTIONS UTILITAIRES
// ============================================

Utilisateur* creerUtilisateur(int id, char nom[], char prenom[], char email[], char password[], char role[]);
Produit* creerProduit(int idProduit, char nomProduit[], float prix, int quantiteStock);
ProduitPanier* creerProduitPanier(int idProduit, char nomProduit[], float prix, int quantite);
Utilisateur scanUtilisateur();
void genererId(int idCommande, int idUtilisateur, char resultat[]);

#endif // EXAMEN_H_INCLUDED
