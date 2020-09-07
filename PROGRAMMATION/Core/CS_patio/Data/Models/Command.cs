namespace PatioSim.Data.Models
{
    using System;
    public class Command : BaseEntity
    {
        public string CustomCommand { get; set; }
        public DeviceType DeviceType { get; set; }
        public bool IsCustom
        {
            get { return !string.IsNullOrWhiteSpace(CustomCommand); }
        }

        public DeviceCommand[] DeviceCommands { get; set; }

#nullable enable
        public Guid? PredefinedCommandId { get; set; }
        public PredefinedCommand? PredefinedCommand { get; set; }
    }
}