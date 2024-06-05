// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRMainMenuWidget.generated.h"

class UButton;
class UWidgetSwitcher;
class UVCRCreateSessionWidget;
class UVCRMenuButton;

UCLASS()
class VIRTUALCHATROOM_API UVCRMainMenuWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

public:
    virtual void NativeOnInitialized();

protected:
    UFUNCTION()
    void ChangeActiveWidget(UVCRMenuButton* MenuButton);

    UFUNCTION()
    void QuitGame();

    UPROPERTY(meta = (BindWidget))
    UWidgetSwitcher* OnlineWidgetSwitcher;

    UPROPERTY(meta = (BindWidget))
    UVCRMenuButton* CreateRoomButton;

    UPROPERTY(meta = (BindWidget))
    UVCRMenuButton* JoinRoomButton;

    UPROPERTY(meta = (BindWidget))
    UVCRMenuButton* QuitGameButton;

    UPROPERTY()
    UVCRCreateSessionWidget* CreateSession;

    UPROPERTY()
    TMap<UVCRMenuButton*, UUserWidget*> WidgetSwitcherMap;
};
