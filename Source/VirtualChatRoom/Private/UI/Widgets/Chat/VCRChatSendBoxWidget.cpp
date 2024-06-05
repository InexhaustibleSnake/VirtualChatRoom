// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatSendBoxWidget.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Components/EditableTextBox.h"
#include "Logic/VCRChatGameState.h"

void UVCRChatSendBoxWidget::NativeOnInitialized() 
{
    Super::NativeOnInitialized();

    if (SendTextButton)
    {
        SendTextButton->OnClicked.AddDynamic(this, &UVCRChatSendBoxWidget::SendMessage);
    }
}

void UVCRChatSendBoxWidget::SendMessage() 
{
    if (!GetWorld()) return;

    const auto GameState = Cast<AVCRChatGameState>(GetWorld()->GetGameState());
    if (!GameState) return;

    GameState->BroadcastNewMessage("Player", GetMessageText().ToString());
}

FText UVCRChatSendBoxWidget::GetMessageText() const
{
    return ChatSendTextBlock ? ChatSendTextBlock->GetText() : FText();
}
