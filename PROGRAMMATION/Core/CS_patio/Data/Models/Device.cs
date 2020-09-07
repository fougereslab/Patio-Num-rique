namespace PatioSim.Data.Models
{
    public class Device : BaseEntity
    {
        public DeviceType DeviceType { get; set; }

        public Command[] Commands { get; set; }
        public DeviceCommand[] DeviceCommands { get; set; }
    }

    public enum DeviceType
    {
        OnOff,
        LedPanel,
        LedSphere,
        LedStrip
    }
}