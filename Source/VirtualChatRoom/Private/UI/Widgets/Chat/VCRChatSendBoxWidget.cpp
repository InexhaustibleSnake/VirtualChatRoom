// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatSendBoxWidget.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Components/EditableTextBox.h"

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

}

FText UVCRChatSendBoxWidget::GetMessageText() const
{
    return ChatSendTextBlock ? ChatSendTextBlock->GetText() : FText();
}
