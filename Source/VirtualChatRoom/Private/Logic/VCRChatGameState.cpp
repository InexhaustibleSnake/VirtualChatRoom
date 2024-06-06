// This project is made for a test assignment

#include "Logic/VCRChatGameState.h"

void AVCRChatGameState::BroadcastNewMessage(const FString& PlayerName, const FString& MessageText)
{
    if (!HasAuthority())
    {
        ServerBroadcastNewMessage(PlayerName, MessageText);
        return;
    }

    MulticastBroadcastNewMessage(PlayerName, MessageText);
}

void AVCRChatGameState::ServerBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    BroadcastNewMessage(PlayerName, MessageText);
}

void AVCRChatGameState::MulticastBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText) 
{
    OnSendNewMessageSignature.Broadcast(PlayerName, MessageText);
}

