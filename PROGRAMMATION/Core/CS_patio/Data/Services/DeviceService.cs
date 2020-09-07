namespace PatioSim.Data.Services
{
    using System;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.EntityFrameworkCore;
    using PatioSim.Data.Contexts.PostgreSQL;
    using PatioSim.Data.Models;
    public class DeviceService
    {
        private readonly PatioContext _context;

        public DeviceService(PatioContext context)
        {
            _context = context;
        }


        public Task<Device[]> GetDevicesAsync()
        {
            return _context.Devices
                           .Where(c => !c.IsDisabled)
                           .Select(device => new Device
                           {
                               ID = device.ID,
                               Name = device.Name,
                               Description = device.Description,
                           })
                            .ToArrayAsync();
        }

        public Task<bool> CreateDeviceAsync(Device device)
        {
            if (device == null
             || string.IsNullOrWhiteSpace(device.Name))
                return null;

            using (var transaction = _context.Database.BeginTransaction())
            {
                try
                {
                    device.ID = Guid.NewGuid();
                    _context.Devices.AddAsync(device);
                    return Task.FromResult(true);
                }
                catch
                {
                    return null;
                }
            }
        }
    }
}
