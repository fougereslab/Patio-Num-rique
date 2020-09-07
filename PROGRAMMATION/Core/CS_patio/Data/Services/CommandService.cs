namespace PatioSim.Data.Services
{
    using System.Threading.Tasks;
    using Microsoft.EntityFrameworkCore;
    using PatioSim.Data.Contexts.PostgreSQL;
    using PatioSim.Data.Models;
    using System.Linq;
    public class CommandService
    {
        private readonly PatioContext _context;

        public CommandService(PatioContext context)
        {
            _context = context;
        }

        public Task<Command[]> GetCommandsAsync()
        {
            return _context.Commands
                           .Where(c => !c.IsDisabled)
                           .Select(command => new Command
                           {
                               ID = command.ID,
                               Name = command.Name,
                               Description = command.Description,
                               CustomCommand = command.CustomCommand
                           })
                           .ToArrayAsync();
        }
    }
}
