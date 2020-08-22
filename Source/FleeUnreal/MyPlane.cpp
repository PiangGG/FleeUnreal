// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlane.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "FleePlayer.h"

// Sets default values
AMyPlane::AMyPlane()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(FName("SceneComp"));
	SceneCompEnd1= CreateDefaultSubobject<USceneComponent>(FName("SceneCompEnd1"));
	SceneCompEnd2= CreateDefaultSubobject<USceneComponent>(FName("SceneCompEnd2"));
	RootComponent = SceneComp;
	SceneCompEnd1->SetupAttachment(SceneComp);
	SceneCompEnd2->SetupAttachment(SceneComp);

	Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh1"));
	Mesh1->SetupAttachment(SceneComp);

	Mesh2 = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh2"));
	Mesh2->SetupAttachment(SceneComp);

	Box1 = CreateDefaultSubobject<UBoxComponent>(FName("Box1"));
	Box1->SetupAttachment(SceneComp);
	Box1->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box1->SetCollisionResponseToAllChannels(ECR_Ignore);
	Box1->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	Box1->OnComponentBeginOverlap.AddDynamic(this,&AMyPlane::OnBox1OverlapBegin);
	Box1->OnComponentEndOverlap.AddDynamic(this, &AMyPlane::OnBox1OverlapEnd);

	Box2 = CreateDefaultSubobject<UBoxComponent>(FName("Box2"));
	Box2->SetupAttachment(SceneComp);
	Box2->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box2->SetCollisionResponseToAllChannels(ECR_Ignore);
	Box2->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Box2->OnComponentBeginOverlap.AddDynamic(this, &AMyPlane::OnBox2OverlapBegin);
	Box2->OnComponentEndOverlap.AddDynamic(this, &AMyPlane::OnBox2OverlapEnd);
	
	Box3 = CreateDefaultSubobject<UBoxComponent>(FName("Box3"));
	Box3->SetupAttachment(SceneComp);
	Box3->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box3->SetCollisionResponseToAllChannels(ECR_Ignore);
	Box3->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Box3->OnComponentBeginOverlap.AddDynamic(this, &AMyPlane::OnBox3OverlapBegin);
	Box3->OnComponentEndOverlap.AddDynamic(this, &AMyPlane::OnBox3OverlapEnd);
}

// Called when the game starts or when spawned
void AMyPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPlane::OnBox1OverlapBegin(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->Destroy();
	UE_LOG(LogTemp, Warning, TEXT("death"));
}

void AMyPlane::OnBox1OverlapEnd(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AMyPlane::OnBox2OverlapBegin(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin"));
	AFleePlayer* Player = Cast<AFleePlayer>(OtherActor);
	//if (Player->bIsCanSpawnPlane == false||Player==nullptr)return;
	Player->bIsCanSpawnPlane = false;
	SpawnLocation = FVector(SceneCompEnd1->GetComponentLocation().X+ FMath::Rand() % 200, SceneCompEnd1->GetComponentLocation().Y + FMath::Rand() % 200, SceneCompEnd1->GetComponentLocation().Z + FMath::Rand() % 300);
	SpawnRotator = FRotator(-(SceneCompEnd1->GetComponentRotation().Yaw + FMath::Rand() % 45),0,0/*(SceneCompEnd1->GetComponentRotation().Yaw+FMath::Rand() % 45), (Player->GetActorRotation().Yaw + FMath::Rand() %10)*/);
	AMyPlane* newAMyPlane=GetWorld()->SpawnActor<AMyPlane>(GetClass(), SpawnLocation, SpawnRotator);
}

void AMyPlane::OnBox2OverlapEnd(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End %d"));
	AFleePlayer* Player = Cast<AFleePlayer>(OtherActor);
	if (Player)
	{
		Player->bIsCanSpawnPlane = true;
	}
	
	this->Destroy();
}

void AMyPlane::OnBox3OverlapBegin(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin"));
	AFleePlayer* Player = Cast<AFleePlayer>(OtherActor);
	//if (Player->bIsCanSpawnPlane == false||Player==nullptr)return;
	Player->bIsCanSpawnPlane = false;
	SpawnLocation = FVector(SceneCompEnd2->GetComponentLocation().X + FMath::Rand() % 200, SceneCompEnd2->GetComponentLocation().Y + FMath::Rand() % 200, SceneCompEnd2->GetComponentLocation().Z + FMath::Rand() % 300);
	SpawnRotator = FRotator(-(SceneCompEnd1->GetComponentRotation().Yaw + FMath::Rand() % 45), 0, 0);
	AMyPlane* newAMyPlane = GetWorld()->SpawnActor<AMyPlane>(GetClass(), SpawnLocation, SpawnRotator);
}

void AMyPlane::OnBox3OverlapEnd(UPrimitiveComponent* ActorComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End %d"));
	AFleePlayer* Player = Cast<AFleePlayer>(OtherActor);
	if (Player)
	{
		Player->bIsCanSpawnPlane = true;
	}

	this->Destroy();
}

