import QtQuick 6.2
import net.alefbet 1.0

EcranChat {
    saisie.onEditingFinished: {
        //Si l'utilisateur saisit du texte dans le champ
        //ce slot sera exécuté
        if(saisie.text !== "") {
            //On ajoute le texte de l'utilisateur au modèle de la vue
            //En conséquence, la vue, lorsqu'elle se mettra à jour
            //lira le nouveau message dans le modèle
            echangesModel.append( { texte: saisie.text, emetteur: "local" } )

            //Puis on envoie le message
            ControleurReseau.envoieMessage(saisie.text)

            //On vide le champ de saisie pou indiquer à l'utilisateur
            //qu'on a bien traité sa saisie et lui permettre d'en faire
            //une nouvelle
            saisie.clear()
        }
    }

    Connections {
        target: saisie.Keys
        function onReturnPressed(event) {
            //Si l'utilisateur tape sur la touche Entrée
            //du clavier ce slot sera appelé
            saisie.editingFinished();
        }
    }
    Connections {
        target: ControleurReseau
        function onMessage(message) {
            //Si un message est reçu ce slot sera appelé
            //On ajoute directement le message au modèle de la vue
            echangesModel.append( { texte: message.message, emetteur: message.emetteur } )
        }
    }

}
