#include<iostream>
#include<cstring>  // CORRECTION: ajout pour strcmp
#include"EXAMEN.hpp"

using namespace std;

int main()
{
    // ============================================
    // DÉCLARATION DES VARIABLES ET LISTES
    // ============================================
    
    ListeMonoUtilisateur liste;           // Liste des utilisateurs
    ListeMonoProduit liste1;              // Liste des produits
    ListeMonoProduitPanier liste2;        // Liste des produits dans le panier
    
    // Variables pour les choix de menu
    int d, e, Uti, pan, cli, com, position, idCommande, idUtilisateur, Prod;  // CORRECTION: déclarations complètes
    
    // Variables pour les données utilisateur
    char email[35], password[30], nomUtil[35], nomProd[35];
    char role[20];  // CORRECTION: variable role déclarée
    
    // ============================================
    // AJOUT D'UN UTILISATEUR ADMIN PAR DÉFAUT
    // ============================================
    // Cet utilisateur permet de se connecter la première fois
    liste.ajouter(101, "Diallo", "Amadou", "amadou@gmail.com", "amadou123", "Admin");

    // ============================================
    // BOUCLE PRINCIPALE DU PROGRAMME
    // ============================================
    do{
        d = afficherMenuProgramme();  // Affiche menu et récupère le choix
        system("cls");  // Efface l'écran
        
        switch(d){
            case 1:  // SE CONNECTER
                cout << "=== Se connecter ===" << endl;
                cout << "Votre Email : ";
                cin >> email;
                cout << "Votre password: ";
                cin >> password;
                
                // Demande du rôle avec validation
                do{
                    cout << "Votre Role (Admin/Client) : ";
                    cin >> role;
                } while(strcmp(role, "Admin") != 0 && strcmp(role, "Client") != 0);  // CORRECTION: && et strcmp
                
                // ============================================
                // VÉRIFICATION DES IDENTIFIANTS
                // ============================================
                if(liste.seConnecter(email, password, role)){  // CORRECTION: appel correct
                    
                    // ============================================
                    // INTERFACE ADMINISTRATEUR
                    // ============================================
                    if(strcmp(role, "Admin") == 0){  // CORRECTION: == au lieu de =
                        cout << "=== Bienvenue ADMIN ===" << endl;
                        system("pause");

                        do{
                            e = afficherMenuAdmin();
                            system("cls");

                            switch(e){
                                case 1:  // GESTION DES UTILISATEURS
                                    cout << "=== Gestion des Utilisateurs ===" << endl;
                                    system("pause");
                                    
                                    do{
                                        Uti = GestionUtilisateur();
                                        system("cls");
                                        
                                        switch(Uti){
                                            case 1:  // Ajouter
                                                {  // AJOUT: bloc pour variables locales
                                                    cout << "=== Ajouter Un utilisateur ===" << endl;
                                                    Utilisateur u = scanUtilisateur();  // CORRECTION: appel correct
                                                    liste.ajouter(u.id, u.nom, u.prenom, u.email, u.password, u.role);
                                                    liste.sauvegarderFichier();
                                                    system("pause");
                                                }
                                                break;
                                                
                                            case 2:  // Modifier
                                                cout << "=== Modifier Un Utilisateur ===" << endl;
                                                cout << "Email de l'utilisateur : ";
                                                cin >> email;
                                                liste.modifierUtilisateur(email);
                                                liste.sauvegarderFichier();
                                                system("pause");
                                                break;
                                                
                                            case 3:  // Supprimer
                                                cout << "=== Supprimer Un Utilisateur ===" << endl;
                                                cout << "Nom de l'utilisateur : ";
                                                cin >> nomUtil;
                                                liste.supprimerUtilisateur(nomUtil);  // CORRECTION: appel correct
                                                liste.sauvegarderFichier();
                                                system("pause");
                                                break;
                                                
                                            case 4:  // Lister
                                                cout << "=== Lister les Utilisateurs ===" << endl;
                                                liste.afficherTous();
                                                system("pause");
                                                break;
                                                
                                            case 5:  // Retour
                                                cout << "Retour au menu principal..." << endl;
                                                break;
                                                
                                            default:
                                                cout << "Choix invalide. Veuillez reessayer." << endl;
                                                system("pause");
                                        }
                                    } while (Uti != 5);  // CORRECTION: point-virgule ajouté
                                    break;
                                    
                                case 2:  // GESTION DES PRODUITS
                                    cout << "=== Gestion des Produits ===" << endl;
                                    system("pause");
                                    
                                    do{
                                        Prod = GestionProduit();  // CORRECTION: variable déclarée
                                        system("cls");
                                        
                                        switch(Prod){
                                            case 1:  // Ajouter
                                                {
                                                    int idProduit, quantiteStock;
                                                    char nomProduit[35];
                                                    float prix;
                                                    
                                                    cout << "=== Ajouter Un Produit ===" << endl;
                                                    cout << "ID Produit : ";
                                                    cin >> idProduit;
                                                    cout << "Nom Produit : ";
                                                    cin >> nomProduit;
                                                    cout << "Prix : ";
                                                    cin >> prix;
                                                    cout << "Quantite en stock : ";
                                                    cin >> quantiteStock;
                                                    
                                                    liste1.ajouterProduit(idProduit, nomProduit, prix, quantiteStock);
                                                    liste1.sauvegarderFichierProduit();
                                                    system("pause");
                                                }
                                                break;
                                                
                                            case 2:  // Modifier
                                                cout << "=== Modifier Un Produit ===" << endl;
                                                cout << "Nom du produit : ";
                                                cin >> nomProd;
                                                liste1.modifierProduit(nomProd);
                                                liste1.sauvegarderFichierProduit();
                                                system("pause");
                                                break;
                                                
                                            case 3:  // Supprimer
                                                cout << "=== Supprimer Un Produit ===" << endl;
                                                cout << "Nom du produit : ";
                                                cin >> nomProd;
                                                liste1.supprimerProduit(nomProd);
                                                liste1.sauvegarderFichierProduit();
                                                system("pause");
                                                break;
                                                
                                            case 4:  // Lister
                                                cout << "=== Lister les Produits ===" << endl;
                                                liste1.afficherTousProduit();
                                                system("pause");
                                                break;
                                                
                                            case 5:  // Retour
                                                cout << "Retour..." << endl;
                                                break;
                                                
                                            default:
                                                cout << "Choix invalide. Veuillez reessayer." << endl;
                                                system("pause");
                                        }
                                    } while (Prod != 5);  // CORRECTION: point-virgule ajouté
                                    break;
                                    
                                case 3:  // CONSULTER LES COMMANDES
                                    cout << "=== Consulter Toutes les Commandes ===" << endl;
                                    system("pause");
                                    
                                    do {
                                        com = afficherCommande();  // CORRECTION: variable déclarée
                                        system("cls");
                                        
                                        switch(com){
                                            case 1:
                                                cout << "=== Liste des commandes ===" << endl;
                                                cout << "Fonctionnalite a implementer..." << endl;
                                                system("pause");
                                                break;
                                                
                                            case 2:
                                                cout << "=== Details des lignes de commandes ===" << endl;
                                                cout << "Fonctionnalite a implementer..." << endl;
                                                system("pause");
                                                break;
                                                
                                            case 3:
                                                cout << "=== Total Par Commandes ===" << endl;
                                                cout << "Fonctionnalite a implementer..." << endl;
                                                system("pause");
                                                break;
                                                
                                            case 4:
                                                cout << "Retour..." << endl;
                                                break;
                                                
                                            default:
                                                cout << "Choix invalide. Veuillez reessayer." << endl;
                                                system("pause");
                                        }
                                    } while (com != 4);  // CORRECTION: point-virgule ajouté
                                    break;
                                    
                                case 4:  // DÉCONNEXION
                                    cout << "=== Deconnexion ===" << endl;
                                    system("pause");
                                    break;
                                    
                                default:
                                    cout << "Choix invalide. Veuillez reessayer." << endl;
                                    system("pause");
                            }
                        } while (e != 4);  // CORRECTION: point-virgule ajouté
                        
                    } else {  // CORRECTION: else ajouté pour Client
                        
                        // ============================================
                        // INTERFACE CLIENT
                        // ============================================
                        cout << "==== Bienvenue Client ====" << endl;
                        system("pause");
                        
                        do{
                            cli = afficherMenuClient();  // CORRECTION: ordre corrigé
                            system("cls");
                            
                            switch(cli){  // CORRECTION: deux-points au lieu de :
                                case 1:  // Consulter les produits
                                    cout << "=== Consulter les produits ===" << endl;
                                    cout << "Produits Disponibles :" << endl;
                                    liste1.afficherTousProduit();
                                    system("pause");
                                    break;
                                    
                                case 2:  // Gérer le panier
                                    cout << "=== Gerer Mon Panier ===" << endl;
                                    system("pause");
                                    
                                    do {
                                        pan = afficherMenuPanier();
                                        system("cls");
                                        
                                        switch(pan){  // CORRECTION: switch correct
                                            case 1:  // Ajouter au panier
                                                {
                                                    int idProduit, quantite;
                                                    char nomProduit[35];
                                                    float prix;
                                                    
                                                    cout << "=== Ajouter Un Produit au Panier ===" << endl;
                                                    cout << "ID Produit : ";
                                                    cin >> idProduit;
                                                    cout << "Nom Produit : ";
                                                    cin >> nomProduit;
                                                    cout << "Prix : ";
                                                    cin >> prix;
                                                    cout << "Quantite : ";
                                                    cin >> quantite;
                                                    
                                                    liste2.ajouterProduitPanier(idProduit, nomProduit, prix, quantite);
                                                    system("pause");
                                                }
                                                break;
                                                
                                            case 2:  // Modifier quantité
                                                cout << "=== Modifier La quantite ===" << endl;
                                                cout << "Nom du produit : ";
                                                cin >> nomProd;
                                                liste2.modifierQuantitePanier(nomProd);
                                                system("pause");
                                                break;
                                                
                                            case 3:  // Supprimer du panier
                                                cout << "=== Supprimer un produit Du panier ===" << endl;
                                                cout << "Position du produit : ";
                                                cin >> position;
                                                liste2.supprimerProduitPanier(position);
                                                system("pause");
                                                break;
                                                
                                            case 4:  // Afficher le panier
                                                cout << "=== Afficher Le panier ===" << endl;
                                                liste2.afficherTousProduitPanier();
                                                system("pause");
                                                break;
                                                
                                            case 5:  // Vider le panier
                                                cout << "=== Vider le Panier ===" << endl;
                                                liste2.viderPanier();
                                                system("pause");
                                                break;
                                                
                                            case 6:  // Retour
                                                cout << "Retour..." << endl;
                                                break;
                                                
                                            default:
                                                cout << "Choix invalide. Veuillez reessayer." << endl;
                                                system("pause");
                                        }
                                    } while (pan != 6);  // CORRECTION: point-virgule ajouté
                                    break;
                                    
                                case 3:  // Valider la commande
                                    {
                                        char idGenere[20];
                                        cout << "=== Valider la Commande ===" << endl;
                                        cout << "ID Commande : ";
                                        cin >> idCommande;
                                        cout << "ID Utilisateur : ";
                                        cin >> idUtilisateur;
                                        genererId(idCommande, idUtilisateur, idGenere);
                                        cout << "ID Genere : " << idGenere << endl;
                                        cout << "Commande validee avec succes!" << endl;
                                        system("pause");
                                    }
                                    break;
                                    
                                case 4:  // Consulter mes commandes
                                    cout << "=== Consulter Mes Commandes ===" << endl;
                                    cout << "Fonctionnalite a implementer..." << endl;
                                    system("pause");
                                    break;
                                    
                                case 5:  // Déconnexion
                                    cout << "=== Deconnexion ===" << endl;
                                    system("pause");
                                    break;
                                    
                                default:
                                    cout << "Choix invalide. Veuillez reessayer." << endl;
                                    system("pause");
                            }
                        } while (cli != 5);  // CORRECTION: point-virgule ajouté
                    }  // CORRECTION: fermeture du else
                    
                } else {
                    // Identifiants incorrects
                    cout << "Email, password ou role incorrect!" << endl;
                    system("pause");
                }
                break;
                
            case 2:  // QUITTER
                cout << "=== Au revoir ! ===" << endl;
                break;
                
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
                system("pause");
        }
    } while (d != 2);  // CORRECTION: point-virgule ajouté

    return 0;
}
