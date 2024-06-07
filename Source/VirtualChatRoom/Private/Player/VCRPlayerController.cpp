// This project is made for a test assignment

#include "Player/VCRPlayerController.h"
#include "Logic/VCRChatGameState.h"

void AVCRPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeGameOnly());
    SetShowMouseCursor(false);
}

void AVCRPlayerController::SendMessage(const FString& PlayerName, const FString& MessageText)
{
    if (!HasAuthority())
    {
        ServerSendMessage(PlayerName, MessageText);
        return;
    }

    const auto GameState = GetChatGameState();
    if (!GameState) return;

    GameState->BroadcastNewMessage(PlayerName, MessageText);
}

void AVCRPlayerController::ServerSendMessage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    SendMessage(PlayerName, MessageText);
}

AVCRChatGameState* AVCRPlayerController::GetChatGameState() const
{
    return GetWorld() ? Cast<AVCRChatGameState>(GetWorld()->GetGameState()) : nullptr;
}

void AVCRPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent) return;

    InputComponent->BindAction("OpenChat", IE_Pressed, this, &AVCRPlayerController::OpenChat);

    DECLARE_DELEGATE_OneParam(FOpenChatSignature, bool);
    InputComponent->BindAction<FOpenChatSignature>(
        "OpenPlayersList", IE_Pressed, this, &AVCRPlayerController::ChangePlayerListVisibility, true);

    InputComponent->BindAction<FOpenChatSignature>(
        "OpenPlayersList", IE_Released, this, &AVCRPlayerController::ChangePlayerListVisibility, false);
}

void AVCRPlayerController::OpenChat()
{
    SetShowMouseCursor(!bShowMouseCursor);
    bShowMouseCursor ? SetInputMode(FInputModeGameAndUI()) : SetInputMode(FInputModeGameOnly());
}

void AVCRPlayerController::ChangePlayerListVisibility(bool IsVisible)
{
    OnWantPlayersListSignature.Broadcast(IsVisible);
}

void AVCRPlayerController::OnNewMessageReceived(const FString& PlayerName, const FString& MessageText)
{
    OnSendNewMessageSignature.Broadcast(PlayerName, MessageText);
}
