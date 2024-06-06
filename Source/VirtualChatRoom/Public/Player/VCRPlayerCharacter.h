// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VCRPlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class VIRTUALCHATROOM_API AVCRPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AVCRPlayerCharacter();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    void SetupCharacterMesh();

    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void LookPitch(float Amount);
    void LookYaw(float Amount);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UCameraComponent* MainCamera;

    UPROPERTY(Transient)
    FName CameraMeshSocketName = "CameraSocket";

    float TurnPitchRate = 90.0f;

    float TurnYawRate = 90.0f;
};
