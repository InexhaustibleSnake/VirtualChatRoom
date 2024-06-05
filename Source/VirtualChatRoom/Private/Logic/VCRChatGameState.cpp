// This project is made for a test assignment

#include "Logic/VCRChatGameState.h"

void AVCRChatGameState::BroadcastNewMessage(const FString& PlayerName, const FString& MessageText)
{
    if (!HasAuthority())
    {
        ServerBroadcastNewMesssage(PlayerName, MessageText);
        return;
    }

    MulticastBroadcastNewMesssage_Implementation(PlayerName, MessageText);
}

void AVCRChatGameState::ServerBroadcastNewMesssage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    BroadcastNewMessage(PlayerName, MessageText);
}

void AVCRChatGameState::MulticastBroadcastNewMesssage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    OnSendNewMessageSignature.Broadcast(PlayerName, MessageText);
}
