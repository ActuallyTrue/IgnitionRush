// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	//OnCalculateCustomPhysics.BindUObject(this, &APlayerCharacter::CustomPhysics);
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//cam->AttachTo(RootComponent);

	arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	arm->AttachTo(RootComponent);
	arm->TargetArmLength = 300.f;
	arm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	/*arm->bEnableCameraLag = true;
	arm->CameraLagSpeed = 2.f;
	arm->CameraLagMaxDistance = 1.5f;

	arm->bEnableCameraRotationLag = true;
	arm->CameraRotationLagSpeed = 4.f;
	arm->CameraLagMaxTimeStep = 1.f;*/

	cam->AttachTo(arm, USpringArmComponent::SocketName);

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
	//Add custom physics on RootComponent's BodyInstance
	/*if (RootComponent->GetBodyInstance() != NULL) { (not working right now I GUESS because the rootcomponent is just a scene component and it has no body instance????
		RootComponent->GetBodyInstance()->AddCustomPhysics(OnCalculateCustomPhysics);
	}*/

	if (jumping) {
		Jump();
	}


}

void APlayerCharacter::CustomPhysics(float DeltaTime, FBodyInstance* BodyInstance) {
	PhysicsTick(DeltaTime);
}

void APlayerCharacter::PhysicsTick_Implementation(float SubstepDeltaTime) {
	//physics code goes here...
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
		AddMovementInput(GetActorRightVector(), value);
	}
}

void APlayerCharacter::VerticalMove(float value) {
	if (value) {
		AddMovementInput(GetActorForwardVector(), value);
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

