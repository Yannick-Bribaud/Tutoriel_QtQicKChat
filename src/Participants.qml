import QtQuick 6.2
import QtQuick.Controls 6.2
import net.alefbet 1.0

EcranParticipants {

    Component.onCompleted: {
        //Lorsque la vue est créée, on initialise le modèle
        //de la vue des participants avec un premier élément
        //correspondant à la session de chat locale
        participantsModel.append( { nom: "Local", type: "local"} )
    }

    Connections {
        target: ControleurReseau

        function onMessage(message) {
            //Si un message est reçu, cet slot sera appelé
            console.debug("émetteur : " +message.emetteur)
            if(!clientsConnus.includes(message.emetteur)) {
                //Si l'émetteur du message n'est pas déjà connue
                //on récupère son nom et on l'ajoute au modèle de la vue
                participantsModel.append( { nom: message.emetteur, type: "distant" } )
                //on garde de côté la liste des émetteur déjà connus
                clientsConnus.push(message.emetteur)
            }
        }
    }
}
