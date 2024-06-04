// This project is made for a test assignment

#include "Player/VCRPlayerCharacter.h"
#include "Camera/CameraComponent.h"

AVCRPlayerCharacter::AVCRPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    MainCamera = CreateDefaultSubobject<UCameraComponent>("MainCamera");
    MainCamera->SetupAttachment(GetMesh(), CameraMeshSocketName);
    MainCamera->bUsePawnControlRotation = true;

    GetMesh()->SetOwnerNoSee(true);

    SetupCharacterMesh();
}

void AVCRPlayerCharacter::SetupCharacterMesh()
{
    if (!GetMesh()) return;

    const FString MeshAssetPath = "SkeletalMesh'/Game/Meshes/StaticMeshes/SK_PlayerCharacter.SK_PlayerCharacter'";

    ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(*MeshAssetPath);

    const auto PlayerMesh = MeshAsset.Object;

    GetMesh()->SetSkeletalMesh(PlayerMesh);

    FVector MeshLocation(0.0f, 0.0f, -90.0f);
    FRotator MeshRotation(0.0f, -90.0f, 0.0f);

    GetMesh()->SetRelativeLocationAndRotation(MeshLocation, MeshRotation);
}

void AVCRPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (!PlayerInputComponent) return;

    PlayerInputComponent->BindAxis("MoveForward", this, &AVCRPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AVCRPlayerCharacter::MoveRight);

    PlayerInputComponent->BindAxis("MouseX", this, &AVCRPlayerCharacter::LookYaw);
    PlayerInputComponent->BindAxis("MouseY", this, &AVCRPlayerCharacter::LookPitch);
}

void AVCRPlayerCharacter::MoveForward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void AVCRPlayerCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void AVCRPlayerCharacter::LookPitch(float Amount)
{
    if (!GetWorld()) return;

    float WorldDeltaSeconds = GetWorld()->GetDeltaSeconds();

    AddControllerPitchInput(Amount * TurnPitchRate * WorldDeltaSeconds);
}

void AVCRPlayerCharacter::LookYaw(float Amount) 
{
    if (!GetWorld()) return;

    float WorldDeltaSeconds = GetWorld()->GetDeltaSeconds();

    AddControllerYawInput(Amount * TurnYawRate * WorldDeltaSeconds);
}
