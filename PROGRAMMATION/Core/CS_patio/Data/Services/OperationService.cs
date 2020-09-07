namespace PatioSim.Data.Services
{
    using System.Threading.Tasks;
    using PatioSim.Data.Models;
    public class DeviceCommandService
    {
      private static readonly DeviceCommand[] DeviceCommands = new[]
        {
            new DeviceCommand{
                Name = "Fountain",
                Command = new Command {
                    Name = "lll"
                }
            },
            new DeviceCommand{
                Name = "Led panel #1"
            }
        };

        public Task<DeviceCommand[]> GetDeviceCommandsAsync()
        {
            return Task.FromResult(DeviceCommands);
        }
    }
}
