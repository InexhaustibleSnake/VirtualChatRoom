// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatSendBoxWidget.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Components/EditableTextBox.h"
#include "Player/VCRPlayerController.h"

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
    const auto PlayerController = Cast<AVCRPlayerController>(GetOwningPlayer());
    if (!PlayerController) return;

    PlayerController->SendMessage("Player", GetMessageText().ToString());
}

FText UVCRChatSendBoxWidget::GetMessageText() const
{
    return ChatSendTextBlock ? ChatSendTextBlock->GetText() : FText();
}
