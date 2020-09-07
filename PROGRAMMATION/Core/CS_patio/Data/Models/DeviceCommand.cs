namespace PatioSim.Data.Models
{
    using System;
    public class DeviceCommand : BaseEntity
    {
        public Guid CommandId { get; set; }
        public Command Command { get; set; }
        public Guid DeviceId { get; set; }
        public Device Device { get; set; }
        public TimeSpan Duration { get; set; } = new TimeSpan(0);
        public DeviceType DeviceType { get; set; } = DeviceType.OnOff;
        public Guid? PreviousDeviceCommandId { get; set; }
        public Guid ScenarioId {get;set;}
        public Scenario Scenario {get;set;}
    }
}