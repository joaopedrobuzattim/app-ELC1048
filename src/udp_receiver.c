#include <openthread/udp.h>
#include <string.h>
#include <openthread/tasklet.h>
#include <openthread/platform/uart.h>
#include <openthread/platform/misc.h>

// Defina uma estrutura para armazenar os dados recebidos
typedef struct
{
    float temperature;
    float luminosity;
    float orientation;
} SensorData;

// Defina uma variável global para armazenar os dados recebidos
SensorData gSensorData;

// Defina uma função de retorno de chamada para lidar com os dados recebidos
void handleUdpReceive(void *aContext, otMessage *aMessage, const otMessageInfo *aMessageInfo)
{
    uint16_t length = otMessageGetLength(aMessage) - otMessageGetOffset(aMessage);

    // Verifique se o tamanho dos dados recebidos corresponde ao tamanho da estrutura SensorData
    if (length == sizeof(SensorData))
    {
        // Leia os dados recebidos na variável global gSensorData
        otMessageRead(aMessage, otMessageGetOffset(aMessage), &gSensorData, sizeof(SensorData));
    }
}

int main(int argc, char *argv[])
{
    otInstance *instance = otInstanceInitSingle(); // Obtenha uma instância do OpenThread
    otUdpSocket socket;
    otSockAddr sockaddr;
    otSysMainloopContext mainloop;

    // Inicialize o soquete UDP
    memset(&socket, 0, sizeof(socket));
    memset(&sockaddr, 0, sizeof(sockaddr));

    // Defina o endereço e a porta do soquete
    sockaddr.mPort = 1024; // Substitua pelo número da porta que você deseja usar

    // Abra o soquete UDP
    otUdpOpen(instance, &socket, handleUdpReceive, NULL);
    otUdpBind(&socket, &sockaddr);

    // O loop principal do programa
    while (true)
    {
        // Atualize o contexto do loop principal
        otSysMainloopUpdate(instance, &mainloop);

        // Aguarde eventos
        otSysMainloopPoll(&mainloop);

        // Execute o processamento de eventos do OpenThread
        otTaskletsProcess(instance);
        otSysProcessDrivers(instance);

        // Processar eventos do sistema
        otSysMainloopProcess(&mainloop);


    }

    return 0;
}



