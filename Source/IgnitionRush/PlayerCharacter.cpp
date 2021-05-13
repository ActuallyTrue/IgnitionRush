// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));


	arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	arm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	arm->TargetArmLength = 300.f;
	arm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	/*arm->bEnableCameraLag = true;
	arm->CameraLagSpeed = 2.f;
	arm->CameraLagMaxDistance = 1.5f;

	arm->bEnableCameraRotationLag = true;
	arm->CameraRotationLagSpeed = 4.f;
	arm->CameraLagMaxTimeStep = 1.f;*/

	cam->AttachToComponent(arm, FAttachmentTransformRules::KeepWorldTransform, USpringArmComponent::SocketName);

	moveInput = FVector2D();
	jumping = false;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (jumping) {
		Jump();
	}


}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &APlayerCharacter::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &APlayerCharacter::VerticalMove);
	InputComponent->BindAxis("HorizontalRotation", this, &APlayerCharacter::HorizontalRot);
	InputComponent->BindAxis("VerticalRotation", this, &APlayerCharacter::VerticalRot);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::CheckJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::CheckJump);
}

void APlayerCharacter::HorizontalRot(float value) {
	if (value) {
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void APlayerCharacter::VerticalRot(float value) {
	if (value) {
		float temp = arm->GetRelativeRotationFromWorld(arm->GetComponentRotation().Quaternion()).Rotator().Pitch + value;
		if (temp < 25 && temp > -65) {
			arm->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
}

void APlayerCharacter::HorizontalMove(float value) {
	if (value) {
		moveInput.X = value;
		///AddMovementInput(GetActorRightVector(), value);
	}
	else {
		moveInput.X = 0;
	}
}

void APlayerCharacter::VerticalMove(float value) {
	if (value) {
		moveInput.Y = value;
		//AddMovementInput(GetActorForwardVector(), value);
	}
	else {
		moveInput.Y = 0;
	}
}

void APlayerCharacter::MovePlayer() {
	if (moveInput.X) {
		AddMovementInput(GetActorRightVector(), moveInput.X);
	}
	if (moveInput.Y) {
		AddMovementInput(GetActorForwardVector(), moveInput.Y);
	}
	
}

void APlayerCharacter::CheckJump() {
	if (jumping) {
		jumping = false;
	}
	else {
		jumping = true;
	}
}

