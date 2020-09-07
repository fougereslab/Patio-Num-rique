namespace PatioSim.Data.Models
{
    using System.Collections.Generic;

    public class Scenario : BaseEntity
    {
        public List<DeviceCommand> DeviceCommands { get; set; }
    }
}