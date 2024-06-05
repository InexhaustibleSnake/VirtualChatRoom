// This project is made for a test assignment

#include "UI/Widgets/InGame/VCRInGameHUDWidget.h"
#include "UI/Widgets/Chat/VCRChatContainerWidget.h"
#include "Logic/VCRChatGameState.h"

void UVCRInGameHUDWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!GetWorld()) return;

    const auto GameState = Cast<AVCRChatGameState>(GetWorld()->GetGameState());
    if (!GameState) return;

    GameState->OnSendNewMessageSignature.AddUObject(this, &UVCRInGameHUDWidget::OnNewMessageReceive);
}

void UVCRInGameHUDWidget::OnNewMessageReceive(const FString& PlayerName, const FString& Message) 
{
    if (!ChatWidget) return;
    ChatWidget->AddMessage(PlayerName, Message);
}
