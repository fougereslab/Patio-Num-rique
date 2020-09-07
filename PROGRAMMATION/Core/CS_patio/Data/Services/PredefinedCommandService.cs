namespace PatioSim.Data.Services
{
    using System.Threading.Tasks;
    using PatioSim.Data.Models;
    public class PredefinedCommandService
    {
      private static readonly PredefinedCommand[] predefinedCommands = new[]
        {
            new PredefinedCommand{
               Name = "BLLBLABL"
            },
            new PredefinedCommand{
                Name = "Led panel #1"
            }
        };

        public Task<PredefinedCommand[]> GetPredefinedCommandsAsync()
        {
            return Task.FromResult(predefinedCommands);
        }
    }
}
