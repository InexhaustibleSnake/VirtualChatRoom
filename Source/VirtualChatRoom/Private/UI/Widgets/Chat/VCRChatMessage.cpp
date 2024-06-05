// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatMessage.h"
#include "Components/TextBlock.h"

void UVCRChatMessage::SetMessage(const FText& MessageText)
{
    SetTextBlockText(MessageTextBlock, MessageText);
}

void UVCRChatMessage::SetPlayerName(const FText& PlayerName)
{
    SetTextBlockText(PlayerNameTextBlock, PlayerName);
}

void UVCRChatMessage::SetTextBlockText(UTextBlock* InTextBlock, const FText& Text)
{
    if (!InTextBlock) return;

    InTextBlock->SetText(Text);
}
