#include<iostream>
#include<cstring>
#include"EXAMEN.hpp"
#include<fstream>
using namespace std;

// ============================================
// FONCTIONS D'AFFICHAGE DES MENUS
// ============================================
// CORRECTION: toutes retournent int pour récupérer le choix

int afficherMenuProgramme() {
    int choix;
    cout << "\n=== Bienvenue ===\n";
    cout << "1. Se Connecter \n";
    cout << "2. QUITTER\n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;  // CORRECTION: retourne le choix
}

int afficherMenuAdmin() {
    int choix;
    cout << "\n=== Menu Administrateur ===\n";
    cout << "1. Gestion des Utilisateurs \n";
    cout << "2. Gestion des Produits\n";
    cout << "3. Consulter toutes les Commandes \n";
    cout << "4. Deconnexion \n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

int GestionUtilisateur(){
    int choix;
    cout << "\n=== Gestion des Utilisateurs ===\n";
    cout << "1. Ajouter Un Utilisateur \n";
    cout << "2. Modifier Un Utilisateur \n";
    cout << "3. Supprimer Un Utilisateur \n";
    cout << "4. Lister Les utilisateurs \n";
    cout << "5. Retour \n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

int GestionProduit(){
    int choix;
    cout << "\n=== Gestion des Produits ===\n";
    cout << "1. Ajouter Un Produit \n";
    cout << "2. Modifier Un Produit \n";
    cout << "3. Supprimer Un Produit \n";
    cout << "4. Lister Les Produits \n";
    cout << "5. Retour \n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

int afficherMenuPanier(){
    int choix;
    cout << "\n=== Gerer le Panier ===\n";
    cout << "1. Ajouter Un Produit au Panier \n";
    cout << "2. Modifier la Quantite \n";
    cout << "3. Supprimer Un Produit du panier \n";
    cout << "4. Afficher Le Panier \n";
    cout << "5. Vider Le Panier \n";
    cout << "6. Retour \n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

int afficherMenuClient() {
    int choix;
    cout << "\n=== Menu Client ===\n";
    cout << "1. Consulter Les Produits \n";
    cout << "2. Gerer Mon Panier\n";
    cout << "3. Valider La Commande \n";
    cout << "4. Consulter Mes Commandes \n";
    cout << "5. Deconnexion \n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

int afficherCommande(){
    int choix;
    cout << "\n=== Gestion des Commandes ===\n";
    cout << "1. Liste des commandes\n";
    cout << "2. Details des lignes de commandes\n";
    cout << "3. Total Par Commandes\n";
    cout << "4. Retour\n";
    cout << "Votre choix: ";
    cin >> choix;
    return choix;
}

// ============================================
// FONCTIONS DE CRÉATION D'OBJETS
// ============================================

// Crée un nouvel utilisateur et retourne son pointeur
Utilisateur* creerUtilisateur(int id, char nom[], char prenom[], char email[], char password[], char role[]) {
    Utilisateur* nouveau = new Utilisateur;  // Allocation mémoire
    nouveau->id = id;
    strcpy(nouveau->nom, nom);              // CORRECTION: utilisation de strcpy
    strcpy(nouveau->prenom, prenom);
    strcpy(nouveau->email, email);
    strcpy(nouveau->password, password);
    strcpy(nouveau->role, role);
    nouveau->suivant = nullptr;
    return nouveau;
}

// Crée un nouveau produit et retourne son pointeur
Produit* creerProduit(int idProduit, char nomProduit[], float prix, int quantiteStock) {
    Produit* nouveau = new Produit;
    nouveau->idProduit = idProduit;
    strcpy(nouveau->nomProduit, nomProduit);  // CORRECTION: utilisation de strcpy
    nouveau->prix = prix;
    nouveau->quantiteStock = quantiteStock;
    nouveau->suivant = nullptr;
    return nouveau;
}

// Crée un nouveau produit panier et retourne son pointeur
ProduitPanier* creerProduitPanier(int idProduit, char nomProduit[], float prix, int quantite) {
    ProduitPanier* nouveau = new ProduitPanier;
    nouveau->idProduit = idProduit;
    strcpy(nouveau->nomProduit, nomProduit);
    nouveau->prix = prix;
    nouveau->quantite = quantite;
    nouveau->suivant = nullptr;
    return nouveau;
}

// Fonction pour saisir les informations d'un utilisateur
Utilisateur scanUtilisateur(){
    Utilisateur u;
    cout << "ID : ";
    cin >> u.id;
    fflush(stdin);  // Vide le buffer
    cout << "Nom : ";
    cin >> u.nom;
    cout << "Prenom : ";
    cin >> u.prenom;
    cout << "Email: ";
    cin >> u.email;
    cout << "Password: ";
    cin >> u.password;
    cout << "Role (Admin/Client): ";
    cin >> u.role;
    return u;
}

// ============================================
// MÉTHODES DE LA CLASSE ListeMonoUtilisateur
// ============================================

// Ajoute un utilisateur à la fin de la liste
void ListeMonoUtilisateur::ajouter(int id, char nom[], char prenom[], char email[], char password[], char role[]) {
    Utilisateur* nouveau = creerUtilisateur(id, nom, prenom, email, password, role);

    if (tete == nullptr) {
        // Liste vide, le nouveau devient la tête
        tete = nouveau;
    } else {
        // Parcourt jusqu'à la fin et ajoute
        Utilisateur* temp = tete;
        while (temp->suivant != nullptr) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
    taille++;
    cout << "Utilisateur ajoute avec succes ! \n";
}

// Vérifie les identifiants de connexion
bool ListeMonoUtilisateur::seConnecter(char email[], char password[], char role[]){
    Utilisateur* temp = tete;
    bool trouve = false;
    
    while(temp != nullptr){
        // CORRECTION: utilisation de strcmp pour comparer les chaînes
        if(strcmp(temp->email, email) == 0 && 
           strcmp(temp->password, password) == 0 && 
           strcmp(temp->role, role) == 0){
            trouve = true;
            break;  // Utilisateur trouvé
        }
        temp = temp->suivant;
    }
    return trouve;
}

// Affiche tous les utilisateurs de la liste
void ListeMonoUtilisateur::afficherTous() {
    if (tete == nullptr) {
        cout << "Aucun Utilisateur\n";
        return;
    }

    cout << "\n--- LISTE DES UTILISATEURS ---\n";
    Utilisateur* temp = tete;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << " | ";
        cout << temp->nom << " " << temp->prenom << " | ";
        cout << temp->email << " | " << temp->role << "\n";  // CORRECTION: ajout <<
        temp = temp->suivant;
    }
    cout << "Total: " << taille << " Utilisateurs\n";
}

// Sauvegarde les utilisateurs dans un fichier
void ListeMonoUtilisateur::sauvegarderFichier() {
    ofstream fichier("utilisateur.dat");  // CORRECTION: guillemets ajoutés
    if (!fichier) {
        cout << "Erreur d'ouverture du fichier\n";
        return;
    }

    Utilisateur* temp = tete;
    while (temp != nullptr) {
        fichier << temp->id << " " << temp->nom << " "
                << temp->prenom << " " << temp->email << " " 
                << temp->password << " " << temp->role << "\n";
        temp = temp->suivant;
    }

    fichier.close();
    cout << "Donnees sauvegardees dans utilisateur.dat\n";
}

// Modifie un utilisateur par email
void ListeMonoUtilisateur::modifierUtilisateur(char email[]){
    Utilisateur* temp = tete;
    bool trouve = false;
    
    while(temp != nullptr){
        if(strcmp(temp->email, email) == 0){  // CORRECTION: strcmp
            trouve = true;
            cout << "Nouveau Nom : ";
            cin >> temp->nom;
            cout << "Nouveau Prenom : ";
            cin >> temp->prenom;
            cout << "Nouvel Email : ";
            cin >> temp->email;
            cout << "Nouveau Password : ";
            cin >> temp->password;
            cout << "Nouveau Role (Admin/Client) : ";
            cin >> temp->role;
            cout << "Utilisateur modifie avec succes!\n";
            break;
        }
        temp = temp->suivant;
    }
    
    if(!trouve){
        cout << "Utilisateur non trouve!\n";
    }
}

// Supprime un utilisateur par nom
void ListeMonoUtilisateur::supprimerUtilisateur(char nomUtil[]){
    if(tete == nullptr){
        cout << "Liste vide!\n";
        return;
    }
    
    // Cas où c'est le premier élément
    if(strcmp(tete->nom, nomUtil) == 0){
        Utilisateur* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;  // CORRECTION: libération mémoire
        taille--;
        cout << "Utilisateur supprime!\n";
        return;
    }
    
    // Recherche dans le reste de la liste
    Utilisateur* temp = tete;
    while(temp->suivant != nullptr){
        if(strcmp(temp->suivant->nom, nomUtil) == 0){
            Utilisateur* aSupprimer = temp->suivant;
            temp->suivant = aSupprimer->suivant;
            delete aSupprimer;
            taille--;
            cout << "Utilisateur supprime!\n";
            return;
        }
        temp = temp->suivant;
    }
    
    cout << "Utilisateur non trouve!\n";
}

// ============================================
// MÉTHODES DE LA CLASSE ListeMonoProduit
// ============================================

// Ajoute un produit à la fin de la liste
void ListeMonoProduit::ajouterProduit(int idProduit, char nomProduit[], float prix, int quantiteStock) {
    Produit* nouveau = creerProduit(idProduit, nomProduit, prix, quantiteStock);

    if (tete1 == nullptr) {
        tete1 = nouveau;
    } else {
        Produit* temp = tete1;
        while (temp->suivant != nullptr) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
    taille1++;
    cout << "Produit ajoute avec succes ! \n";
}

// Affiche tous les produits
void ListeMonoProduit::afficherTousProduit() {
    if (tete1 == nullptr) {
        cout << "Aucun produit\n";
        return;
    }

    cout << "\n--- LISTE DES PRODUITS ---\n";
    Produit* temp = tete1;
    while (temp != nullptr) {
        cout << "ID: " << temp->idProduit << " | ";
        cout << "Nom: " << temp->nomProduit << " | ";
        cout << "Prix: " << temp->prix << " | ";
        cout << "Stock: " << temp->quantiteStock << "\n";
        temp = temp->suivant;
    }
    cout << "Total: " << taille1 << " Produits\n";
}

// Modifie un produit par nom
void ListeMonoProduit::modifierProduit(char nomProduit[]){
    Produit* temp = tete1;
    bool trouve = false;
    
    while(temp != nullptr){
        if(strcmp(temp->nomProduit, nomProduit) == 0){
            trouve = true;
            cout << "Nouveau Nom du Produit : ";
            cin >> temp->nomProduit;
            cout << "Nouveau Prix : ";
            cin >> temp->prix;
            cout << "Nouvelle Quantite de Stock : ";
            cin >> temp->quantiteStock;
            cout << "Produit modifie avec succes!\n";
            break;
        }
        temp = temp->suivant;
    }
    
    if(!trouve){
        cout << "Produit non trouve!\n";
    }
}

// Supprime un produit par nom
void ListeMonoProduit::supprimerProduit(char nomProd[]){
    if(tete1 == nullptr){
        cout << "Liste vide!\n";
        return;
    }
    
    // Cas où c'est le premier élément
    if(strcmp(tete1->nomProduit, nomProd) == 0){
        Produit* aSupprimer = tete1;
        tete1 = tete1->suivant;
        delete aSupprimer;
        taille1--;
        cout << "Produit supprime!\n";
        return;
    }
    
    // Recherche dans le reste de la liste
    Produit* temp = tete1;
    while(temp->suivant != nullptr){
        if(strcmp(temp->suivant->nomProduit, nomProd) == 0){
            Produit* aSupprimer = temp->suivant;
            temp->suivant = aSupprimer->suivant;
            delete aSupprimer;
            taille1--;
            cout << "Produit supprime!\n";
            return;
        }
        temp = temp->suivant;
    }
    
    cout << "Produit non trouve!\n";
}

// Sauvegarde les produits dans un fichier
void ListeMonoProduit::sauvegarderFichierProduit() {
    ofstream fichier("produit.dat");  // CORRECTION: guillemets ajoutés
    if (!fichier) {
        cout << "Erreur d'ouverture du fichier\n";
        return;
    }

    Produit* temp = tete1;
    while (temp != nullptr) {
        fichier << temp->idProduit << " " << temp->nomProduit << " "
                << temp->prix << " " << temp->quantiteStock << "\n";
        temp = temp->suivant;
    }

    fichier.close();
    cout << "Donnees sauvegardees dans produit.dat\n";
}

// ============================================
// MÉTHODES DE LA CLASSE ListeMonoProduitPanier
// ============================================

// Ajoute un produit au panier
void ListeMonoProduitPanier::ajouterProduitPanier(int idProduit, char nomProduit[], float prix, int quantite) {
    ProduitPanier* nouveau = creerProduitPanier(idProduit, nomProduit, prix, quantite);

    if (tete3 == nullptr) {
        tete3 = nouveau;
    } else {
        ProduitPanier* temp = tete3;
        while (temp->suivant != nullptr) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
    taille2++;
    cout << "Produit ajoute au panier\n";
}

// Modifie la quantité d'un produit dans le panier
void ListeMonoProduitPanier::modifierQuantitePanier(char nomProduit[]){
    ProduitPanier* temp = tete3;
    bool trouve = false;
    
    while(temp != nullptr){
        if(strcmp(temp->nomProduit, nomProduit) == 0){
            trouve = true;
            cout << "Nouvelle Quantite : ";
            cin >> temp->quantite;
            cout << "Quantite modifiee avec succes!\n";
            break;
        }
        temp = temp->suivant;
    }
    
    if(!trouve){
        cout << "Produit non trouve dans le panier!\n";
    }
}

// Supprime un produit du panier à une position donnée
void ListeMonoProduitPanier::supprimerProduitPanier(int position) {
    if (position < 0 || position >= taille2) {
        cout << "Position invalide!\n";
        return;
    }

    // Suppression du premier élément
    if (position == 0) {
        ProduitPanier* aSupprimer = tete3;
        tete3 = tete3->suivant;
        delete aSupprimer;
        taille2--;
        cout << "Produit supprime du panier\n";
        return;
    }

    // Suppression à une position quelconque
    ProduitPanier* temp = tete3;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->suivant;
    }

    ProduitPanier* aSupprimer = temp->suivant;
    temp->suivant = aSupprimer->suivant;
    cout << "Produit supprime du panier\n";
    delete aSupprimer;
    taille2--;
}

// Affiche tous les produits du panier
void ListeMonoProduitPanier::afficherTousProduitPanier() {
    if (tete3 == nullptr) {
        cout << "Panier vide\n";
        return;
    }

    cout << "\n--- CONTENU DU PANIER ---\n";
    ProduitPanier* temp = tete3;
    float total = 0;  // Calcul du total
    
    while (temp != nullptr) {
        cout << "ID: " << temp->idProduit << " | ";
        cout << "Nom: " << temp->nomProduit << " | ";
        cout << "Prix unitaire: " << temp->prix << " | ";
        cout << "Quantite: " << temp->quantite << " | ";
        float sousTotal = temp->prix * temp->quantite;
        cout << "Sous-total: " << sousTotal << "\n";
        total += sousTotal;
        temp = temp->suivant;
    }
    cout << "------------------------\n";
    cout << "TOTAL: " << total << " FCFA\n";
    cout << "Nombre d'articles: " << taille2 << "\n";
}

// Vide complètement le panier
void ListeMonoProduitPanier::viderPanier() {
    while(tete3 != nullptr){
        ProduitPanier* aSupprimer = tete3;
        tete3 = tete3->suivant;
        delete aSupprimer;  // Libération mémoire
    }
    taille2 = 0;
    cout << "Panier vide!\n";
}

// ============================================
// FONCTION UTILITAIRE
// ============================================

// Génère un ID de commande unique en combinant idCommande et idUtilisateur
void genererId(int idCommande, int idUtilisateur, char resultat[]) {
    sprintf(resultat, "%d%d", idCommande, idUtilisateur);  // CORRECTION: sprintf correct
}
