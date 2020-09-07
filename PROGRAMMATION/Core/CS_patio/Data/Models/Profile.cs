namespace PatioSim.Data.Models
{
    public class Profile : BaseEntity
    {
        public string Fullname { get; set; }
        public string Username { get; set; }
        public string PasswordHash { get; set; }
    }
}