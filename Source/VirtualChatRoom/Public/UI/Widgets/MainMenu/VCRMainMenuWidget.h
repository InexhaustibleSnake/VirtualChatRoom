// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "UI/Widgets/MainMenu/VCRCreateSessionWidget.h"
#include "UI/Widgets/VCRMenuItemWidget.h"
#include "UI/Widgets/MainMenu/VCRJoinSessionWidget.h"
#include "VCRMainMenuWidget.generated.h"

class UButton;
class UWidgetSwitcher;
class UVCRMenuButton;
class UUserWidget;

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

    UPROPERTY(meta = (BindWidget))
    UVCRCreateSessionWidget* SessionCreationWidget;

    UPROPERTY(meta = (BindWidget))
    UVCRJoinSessionWidget* SessionSearchWidget;

    TMap<UVCRMenuButton*, UVCRMenuItemWidget*> WidgetSwitcherMap;
};
