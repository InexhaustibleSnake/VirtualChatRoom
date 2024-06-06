// This project is made for a test assignment

#include "Logic/VCRChatGameState.h"
#include "GameFramework/PlayerState.h"
#include "Player/VCRPlayerController.h"

void AVCRChatGameState::BroadcastNewMessage(const FString& PlayerName, const FString& MessageText)
{
    if (!HasAuthority())
    {
        ServerBroadcastNewMesssage(PlayerName, MessageText);
        return;
    }

    for (TObjectIterator<AVCRPlayerController> Itr; Itr; ++Itr)
    {
        if (!*Itr) continue;

        Itr->OnNewMessageReceived(PlayerName, MessageText);
    }

}

void AVCRChatGameState::ServerBroadcastNewMesssage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    BroadcastNewMessage(PlayerName, MessageText);
}

